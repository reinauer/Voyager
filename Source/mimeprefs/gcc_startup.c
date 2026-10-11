/*
 * 68k GCC (libnix) startup for MimePrefs: runs the SAS/C style
 * CONSTRUCTOR_P/DESTRUCTOR_P functions (see gcc_compat.h) around
 * mimeprefs_main(), which is main() in the SAS/C build.
 */

#include <exec/types.h>
#include "gcc_compat.h"

#define MAX_FUNCS 32

struct gcc_func
{
	APTR fn;
	int pri;
};

static struct gcc_func ctors[ MAX_FUNCS ], dtors[ MAX_FUNCS ];
static int numctors, numdtors;

int mimeprefs_main( int argc, char **argv );

static void gcc_add( struct gcc_func *tab, int *num, APTR fn, int pri )
{
	int i, j;

	if( *num >= MAX_FUNCS )
		return;

	/* insertion sort by ascending priority, stable */
	for( i = 0; i < *num && tab[ i ].pri <= pri; i++ )
		;
	for( j = *num; j > i; j-- )
		tab[ j ] = tab[ j - 1 ];

	tab[ i ].fn = fn;
	tab[ i ].pri = pri;
	( *num )++;
}

void gcc_add_constructor( gcc_ctor_fn fn, int pri )
{
	gcc_add( ctors, &numctors, (APTR)fn, pri );
}

void gcc_add_destructor( gcc_dtor_fn fn, int pri )
{
	gcc_add( dtors, &numdtors, (APTR)fn, pri );
}

int main( int argc, char **argv )
{
	int i, rc = 0;

	for( i = 0; i < numctors && rc == 0; i++ )
		rc = ( (gcc_ctor_fn)ctors[ i ].fn )();

	if( rc == 0 )
		rc = mimeprefs_main( argc, argv );

	/* the destructors check what their constructor managed to set up */
	for( i = numdtors - 1; i >= 0; i-- )
		( (gcc_dtor_fn)dtors[ i ].fn )();

	return( rc );
}
