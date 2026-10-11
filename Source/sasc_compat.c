/*
 * SAS/C runtime functions for 68k GCC builds, see sasc_compat.h
 */

#include <string.h>
#include <ctype.h>
#include "sasc_compat.h"

/* Seconds between 1.1.1970 and the AmigaDOS epoch 1.1.1978 */
#define AMIGA_EPOCH_OFFSET 252460800L

int stccpy( char *to, const char *from, int length )
{
	int n = 0;

	if( length <= 0 )
		return( 0 );

	while( --length > 0 && *from )
	{
		*to++ = *from++;
		n++;
	}
	*to = 0;

	return( n + 1 );
}

char *stpblk( const char *p )
{
	while( *p && isspace( (unsigned char)*p ) )
		p++;
	return( (char *)p );
}

char *stpbrk( const char *s, const char *set )
{
	return( strpbrk( s, set ) );
}

void strins( char *to, const char *from )
{
	size_t fl = strlen( from );

	memmove( to + fl, to, strlen( to ) + 1 );
	memcpy( to, from, fl );
}

char *strrev( char *s )
{
	char *b = s, *e = s + strlen( s );

	while( b < --e )
	{
		char c = *b;
		*b++ = *e;
		*e = c;
	}
	return( s );
}

int stch_l( const char *in, long *lvalue )
{
	const char *p = in;
	long v = 0;

	for( ;; p++ )
	{
		int c = *p;

		if( c >= '0' && c <= '9' )
			c -= '0';
		else if( c >= 'a' && c <= 'f' )
			c -= 'a' - 10;
		else if( c >= 'A' && c <= 'F' )
			c -= 'A' - 10;
		else
			break;
		v = ( v << 4 ) | c;
	}
	*lvalue = v;

	return( p - in );
}

int stcd_l( const char *in, long *lvalue )
{
	const char *p = in;
	long v = 0;
	int neg = FALSE;

	if( *p == '-' || *p == '+' )
		neg = ( *p++ == '-' );

	if( !isdigit( (unsigned char)*p ) )
	{
		*lvalue = 0;
		return( 0 );
	}

	while( isdigit( (unsigned char)*p ) )
		v = v * 10 + ( *p++ - '0' );

	*lvalue = neg ? -v : v;

	return( p - in );
}

int stcul_d( char *out, unsigned long lvalue )
{
	char tmp[ 12 ];
	int i = 0, n;

	do
	{
		tmp[ i++ ] = '0' + ( lvalue % 10 );
		lvalue /= 10;
	} while( lvalue );

	for( n = 0; i; n++ )
		out[ n ] = tmp[ --i ];
	out[ n ] = 0;

	return( n );
}

int stcl_d( char *out, long lvalue )
{
	if( lvalue < 0 )
	{
		*out = '-';
		return( stcul_d( out + 1, -(unsigned long)lvalue ) + 1 );
	}
	return( stcul_d( out, lvalue ) );
}

long __datecvt( struct DateStamp *ds )
{
	return( ds->ds_Days * 86400L + ds->ds_Minute * 60L + ds->ds_Tick / TICKS_PER_SECOND + AMIGA_EPOCH_OFFSET );
}

struct DateStamp *__timecvt( long t )
{
	static struct DateStamp ds;

	t -= AMIGA_EPOCH_OFFSET;
	if( t < 0 )
		t = 0;
	ds.ds_Days = t / 86400L;
	t %= 86400L;
	ds.ds_Minute = t / 60;
	ds.ds_Tick = ( t % 60 ) * TICKS_PER_SECOND;

	return( &ds );
}

static int isleap( int y )
{
	return( ( y % 4 == 0 && y % 100 != 0 ) || y % 400 == 0 );
}

static const UBYTE mdays[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*
 * v[0] = year - 1970, v[1] = month (1-12), v[2] = day (1-31),
 * v[3] = hour, v[4] = minute, v[5] = second
 */
void utunpk( long t, char *v )
{
	unsigned long ut = (unsigned long)t;
	unsigned long days = ut / 86400L, secs = ut % 86400L;
	int y = 1970, m = 0;

	for( ;; )
	{
		unsigned long yd = isleap( y ) ? 366 : 365;
		if( days < yd )
			break;
		days -= yd;
		y++;
	}
	for( ;; )
	{
		unsigned long md = mdays[ m ] + ( m == 1 && isleap( y ) );
		if( days < md )
			break;
		days -= md;
		m++;
	}

	v[ 0 ] = y - 1970;
	v[ 1 ] = m + 1;
	v[ 2 ] = days + 1;
	v[ 3 ] = secs / 3600;
	v[ 4 ] = ( secs / 60 ) % 60;
	v[ 5 ] = secs % 60;
}

long utpack( const char *v )
{
	int y, m, year = 1970 + (UBYTE)v[ 0 ];
	unsigned long days = 0;

	for( y = 1970; y < year; y++ )
		days += isleap( y ) ? 366 : 365;
	for( m = 0; m < v[ 1 ] - 1 && m < 12; m++ )
		days += mdays[ m ] + ( m == 1 && isleap( year ) );
	days += v[ 2 ] - 1;

	return( (long)( days * 86400L + v[ 3 ] * 3600L + v[ 4 ] * 60L + v[ 5 ] ) );
}
