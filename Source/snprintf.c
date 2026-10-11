/**************************************************************************

  =======================
  The Voyager Web Browser
  =======================

  Copyright (C) 1995-2003 by
   Oliver Wagner <owagner@vapor.com>
   All Rights Reserved

**************************************************************************/

/*
 * Bounded C sprintf for 68k (SAS/C and GCC).
 *
 * utility.library SNPrintf/VSNPrintf are V47+ only, and exec RawDoFmt has
 * different semantics from C (16 bit %d/%u/%x/%c unless 'l' is given, no
 * %f, no '+', ' ', '#' or '*'), while all callers pass C varargs. This is
 * a small C printf: flags "-+ #0", width and precision (also '*'), the
 * length modifiers h, hh and l, and d i u o x X c s p f (e/g are printed
 * like f). It always NUL terminates and returns the number of characters
 * stored, like the code it replaces.
 */

#include "voyager.h"
#include <stdarg.h>

#if defined( __SASC ) || ( defined( __GNUC__ ) && !defined( __MORPHOS__ ) )

struct snout
{
	char *p;
	char *end;
};

static void sn_c( struct snout *o, char c )
{
	if( o->p < o->end )
		*o->p++ = c;
}

static void sn_rep( struct snout *o, char c, int n )
{
	while( n-- > 0 )
		sn_c( o, c );
}

/*
 * Emit prefix (sign / "0x") and body padded to width. zeros are the
 * leading zeros from the precision, zeropad pads with '0' after the prefix.
 */
static void sn_field( struct snout *o, const char *prefix, int plen, int zeros,
	const char *body, int blen, int width, int left, int zeropad )
{
	int pad = width - plen - zeros - blen;

	if( pad < 0 )
		pad = 0;
	if( !left && !zeropad )
		sn_rep( o, ' ', pad );
	while( plen-- > 0 )
		sn_c( o, *prefix++ );
	if( !left && zeropad )
		sn_rep( o, '0', pad );
	sn_rep( o, '0', zeros );
	while( blen-- > 0 )
		sn_c( o, *body++ );
	if( left )
		sn_rep( o, ' ', pad );
}

/* digits of v in reverse into tmp, returns the count */
static int sn_digits( char *tmp, unsigned long v, int base, int upper )
{
	const char *d = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	int n = 0;

	do
	{
		tmp[ n++ ] = d[ v % base ];
		v /= base;
	} while( v );
	return( n );
}

static int sn_reverse( char *dst, const char *src, int n )
{
	int i;

	for( i = 0; i < n; i++ )
		dst[ i ] = src[ n - 1 - i ];
	return( n );
}

static int voy_vformat( char *str, size_t size, const char *fmt, va_list ap )
{
	struct snout o;

	if( !str || size == 0 )
		return( 0 );

	o.p = str;
	o.end = str + size - 1;

	while( *fmt )
	{
		int left = FALSE, plus = 0, alt = FALSE, zeropad = FALSE;
		int width = 0, prec = -1, lmod = 0;
		char prefix[ 3 ], body[ 48 ], tmp[ 48 ];
		int plen = 0, blen = 0;
		char conv;

		if( *fmt != '%' )
		{
			sn_c( &o, *fmt++ );
			continue;
		}
		fmt++;

		/* flags */
		for( ;; fmt++ )
		{
			if( *fmt == '-' )
				left = TRUE;
			else if( *fmt == '+' )
				plus = '+';
			else if( *fmt == ' ' )
			{
				if( !plus )
					plus = ' ';
			}
			else if( *fmt == '#' )
				alt = TRUE;
			else if( *fmt == '0' )
				zeropad = TRUE;
			else
				break;
		}

		/* width */
		if( *fmt == '*' )
		{
			width = va_arg( ap, int );
			if( width < 0 )
			{
				left = TRUE;
				width = -width;
			}
			fmt++;
		}
		else
		{
			while( *fmt >= '0' && *fmt <= '9' )
				width = width * 10 + ( *fmt++ - '0' );
		}

		/* precision */
		if( *fmt == '.' )
		{
			fmt++;
			prec = 0;
			if( *fmt == '*' )
			{
				prec = va_arg( ap, int );
				if( prec < 0 )
					prec = -1;
				fmt++;
			}
			else
			{
				while( *fmt >= '0' && *fmt <= '9' )
					prec = prec * 10 + ( *fmt++ - '0' );
			}
		}

		/* length modifier: 1 = h, 2 = hh, 3 = l (int and long are both 32 bit) */
		if( *fmt == 'h' )
		{
			lmod = 1;
			if( *++fmt == 'h' )
			{
				lmod = 2;
				fmt++;
			}
		}
		else if( *fmt == 'l' )
		{
			lmod = 3;
			fmt++;
		}

		if( left )
			zeropad = FALSE;

		conv = *fmt;
		if( !conv )
			break;
		fmt++;

		switch( conv )
		{
			case 'd':
			case 'i':
				{
					long v = lmod == 3 ? va_arg( ap, long ) : (long)va_arg( ap, int );
					unsigned long u;

					if( lmod == 1 )
						v = (short)v;
					else if( lmod == 2 )
						v = (signed char)v;
					if( v < 0 )
					{
						prefix[ plen++ ] = '-';
						u = 0UL - (unsigned long)v;
					}
					else
					{
						if( plus )
							prefix[ plen++ ] = (char)plus;
						u = (unsigned long)v;
					}
					if( prec == 0 && u == 0 )
						blen = 0;
					else
						blen = sn_reverse( body, tmp, sn_digits( tmp, u, 10, FALSE ) );
					if( prec >= 0 )
						zeropad = FALSE;
					sn_field( &o, prefix, plen, prec > blen ? prec - blen : 0, body, blen, width, left, zeropad );
				}
				break;

			case 'u':
			case 'o':
			case 'x':
			case 'X':
			case 'p':
				{
					unsigned long u;
					int base = conv == 'o' ? 8 : ( conv == 'u' ? 10 : 16 );
					int zeros;

					if( conv == 'p' )
					{
						u = (unsigned long)va_arg( ap, void * );
						alt = TRUE;
					}
					else
					{
						u = lmod == 3 ? va_arg( ap, unsigned long ) : (unsigned long)va_arg( ap, unsigned int );
						if( lmod == 1 )
							u = (unsigned short)u;
						else if( lmod == 2 )
							u = (unsigned char)u;
					}
					if( prec == 0 && u == 0 )
						blen = 0;
					else
						blen = sn_reverse( body, tmp, sn_digits( tmp, u, base, conv == 'X' ) );
					if( alt && base == 16 && u )
					{
						prefix[ plen++ ] = '0';
						prefix[ plen++ ] = conv == 'X' ? 'X' : 'x';
					}
					zeros = prec > blen ? prec - blen : 0;
					if( alt && base == 8 && !zeros && ( !blen || body[ 0 ] != '0' ) )
						zeros = 1;
					if( prec >= 0 )
						zeropad = FALSE;
					sn_field( &o, prefix, plen, zeros, body, blen, width, left, zeropad );
				}
				break;

			case 'c':
				body[ 0 ] = (char)va_arg( ap, int );
				sn_field( &o, prefix, 0, 0, body, 1, width, left, FALSE );
				break;

			case 's':
				{
					const char *sp = va_arg( ap, const char * );
					int n = 0;

					if( !sp )
						sp = "(null)";
					while( sp[ n ] && ( prec < 0 || n < prec ) )
						n++;
					sn_field( &o, prefix, 0, 0, sp, n, width, left, FALSE );
				}
				break;

			case 'f':
			case 'F':
			case 'e':
			case 'E':
			case 'g':
			case 'G':
				{
					double d = va_arg( ap, double );
					double scale = 1.0;
					unsigned long ip, fp;
					int i;

					if( prec < 0 )
						prec = 6;
					if( prec > 9 )
						prec = 9;
					if( d < 0 )
					{
						prefix[ plen++ ] = '-';
						d = -d;
					}
					else if( plus )
						prefix[ plen++ ] = (char)plus;
					for( i = 0; i < prec; i++ )
						scale *= 10.0;
					d += 0.5 / scale;
					if( d >= 4294967295.0 )
					{
						/* beyond what the formatter handles in 32 bit */
						d = 4294967295.0;
					}
					ip = (unsigned long)d;
					fp = (unsigned long)( ( d - (double)ip ) * scale );
					blen = sn_reverse( body, tmp, sn_digits( tmp, ip, 10, FALSE ) );
					if( prec > 0 || alt )
						body[ blen++ ] = '.';
					if( prec > 0 )
					{
						int n = sn_digits( tmp, fp, 10, FALSE );

						for( i = n; i < prec; i++ )
							body[ blen++ ] = '0';
						blen += sn_reverse( body + blen, tmp, n );
					}
					sn_field( &o, prefix, plen, 0, body, blen, width, left, zeropad );
				}
				break;

			case '%':
				sn_c( &o, '%' );
				break;

			default:
				/* unknown conversion: copy it literally */
				sn_c( &o, '%' );
				sn_c( &o, conv );
				break;
		}
	}

	*o.p = 0;
	return( (int)( o.p - str ) );
}

/* args is a C va_list from the caller's varargs function */
int voy_vsnprintf( char *str, size_t size, const char *format, APTR args )
{
	return( voy_vformat( str, size, format, (va_list)args ) );
}

int STDARGS snprintf( char *str, size_t size, const char *format, ... )
{
	va_list args;
	int n;

	va_start( args, format );
	n = voy_vformat( str, size, format, args );
	va_end( args );
	return( n );
}

#else /* !__SASC */

#include <proto/utility.h>

int voy_vsnprintf( char *str, size_t size, const char *format, APTR args )
{
	return( VSNPrintf( str, size, (const STRPTR)format, args ) );
}

int snprintf( char *str, size_t size, const char *format, ... )
{
	va_list args;
	int result;

	va_start( args, format );
	result = VSNPrintf( str, size, (const STRPTR)format, (APTR)args );
	va_end( args );
	return( result );
}

#endif /* __SASC || 68k GCC */
