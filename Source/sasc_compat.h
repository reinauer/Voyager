#ifndef VOYAGER_SASC_COMPAT_H
#define VOYAGER_SASC_COMPAT_H
/*
 * SAS/C runtime functions for 68k GCC builds
 * ------------------------------------------
 * Voyager uses a handful of sc.lib extensions that libnix does not have.
 * The implementations are in sasc_compat.c and follow the SAS/C semantics.
 */

#if defined( __GNUC__ ) && !defined( __MORPHOS__ )

#include <exec/types.h>
#include <dos/dos.h>

#ifndef min
#define min(a,b) \
	({typeof(a) _a = (a); \
	typeof(b) _b = (b); \
	_a > _b ? _b : _a;})
#endif

#ifndef max
#define max(a,b) \
	({typeof(a) _a = (a); \
	typeof(b) _b = (b);	\
	_a > _b ? _a : _b;})
#endif

int stccpy( char *to, const char *from, int length );
char *stpblk( const char *p );
char *stpbrk( const char *s, const char *set );
void strins( char *to, const char *from );
char *strrev( char *s );
int stch_l( const char *in, long *lvalue );
int stcd_l( const char *in, long *lvalue );
int stcl_d( char *out, long lvalue );
int stcul_d( char *out, unsigned long lvalue );

/* Time helpers. Times are seconds since 1.1.1970 (GMT, see sup.s __tzset) */
long __datecvt( struct DateStamp *ds );
struct DateStamp *__timecvt( long t );
void utunpk( long t, char *v );
long utpack( const char *v );

#endif /* __GNUC__ && !__MORPHOS__ */

#endif /* VOYAGER_SASC_COMPAT_H */
