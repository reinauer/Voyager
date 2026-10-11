/*
 * Shared library entry for the 68k GCC (libnix) builds of the Voyager
 * plugins, see libstart_gcc.h.
 *
 * The romtag has to be in the first hunk, so this file is compiled with
 * -fno-toplevel-reorder and linked first (-nostartfiles). Running the
 * library as a program returns -1 like SAS/C's libent.o does.
 *
 * Exec calls Init/Open/Close/Expunge with the arguments in registers,
 * the assembler stubs below push them on the stack for the C functions.
 */

#include <exec/types.h>
#include <exec/execbase.h>
#include <exec/libraries.h>
#include <exec/nodes.h>
#include <exec/resident.h>
#include <dos/dos.h>
#include <proto/exec.h>

#include "libstart_gcc.h"

#ifndef LIB_VERSION
#error compile libstart_gcc.c with -DLIB_VERSION=<romtag version>
#endif

#define LIBSTART_STR2(x) #x
#define LIBSTART_STR(x) LIBSTART_STR2(x)

struct LibStartBase
{
	struct Library lib;
	BPTR seglist;
};

struct ExecBase *SysBase;

extern const ULONG libstart_inittable[ 4 ];

struct Library *libstart_init_c( struct LibStartBase *base, BPTR seglist );
ULONG libstart_open_c( struct LibStartBase *base );
ULONG libstart_close_c( struct LibStartBase *base );
ULONG libstart_expunge_c( struct LibStartBase *base );

asm(
"	.text\n"
"	.even\n"
"	.globl	_libstart_entry\n"
"_libstart_entry:\n"
"	moveq	#-1,d0\n"
"	rts\n"
"	.even\n"
"	.globl	_libstart_romtag\n"
"_libstart_romtag:\n"
"	.word	0x4afc\n"				/* rt_MatchWord RTC_MATCHWORD */
"	.long	_libstart_romtag\n"		/* rt_MatchTag */
"	.long	_libstart_endskip\n"	/* rt_EndSkip */
"	.byte	0x80\n"					/* rt_Flags RTF_AUTOINIT */
"	.byte	" LIBSTART_STR( LIB_VERSION ) "\n"	/* rt_Version */
"	.byte	9\n"					/* rt_Type NT_LIBRARY */
"	.byte	0\n"					/* rt_Pri */
"	.long	_LibName\n"				/* rt_Name */
"	.long	_LibIdString\n"			/* rt_IdString */
"	.long	_libstart_inittable\n"	/* rt_Init */
"_libstart_endskip:\n"
"\n"
"	.globl	_libstart_init\n"		/* d0 = library, a0 = seglist, a6 = SysBase */
"_libstart_init:\n"
"	movel	a6,_SysBase\n"
"	movel	a0,sp@-\n"
"	movel	d0,sp@-\n"
"	jsr	_libstart_init_c\n"
"	addql	#8,sp\n"
"	rts\n"
"\n"
"	.globl	_libstart_open\n"		/* a6 = library */
"_libstart_open:\n"
"	movel	a6,sp@-\n"
"	jsr	_libstart_open_c\n"
"	addql	#4,sp\n"
"	rts\n"
"\n"
"	.globl	_libstart_close\n"
"_libstart_close:\n"
"	movel	a6,sp@-\n"
"	jsr	_libstart_close_c\n"
"	addql	#4,sp\n"
"	rts\n"
"\n"
"	.globl	_libstart_expunge\n"
"_libstart_expunge:\n"
"	movel	a6,sp@-\n"
"	jsr	_libstart_expunge_c\n"
"	addql	#4,sp\n"
"	rts\n"
"\n"
"	.globl	_libstart_extfunc\n"
"_libstart_extfunc:\n"
"	moveq	#0,d0\n"
"	rts\n"
);

extern void libstart_init( void );

/* RTF_AUTOINIT table: base size, function table, data table, init function */
const ULONG libstart_inittable[ 4 ] =
{
	sizeof( struct LibStartBase ),
	(ULONG)LibFuncTable,
	0,
	(ULONG)libstart_init
};

static void libstart_free( struct LibStartBase *base )
{
	FreeMem( (char *)base - base->lib.lib_NegSize,
		base->lib.lib_NegSize + base->lib.lib_PosSize );
}

struct Library *libstart_init_c( struct LibStartBase *base, BPTR seglist )
{
	base->seglist = seglist;

	base->lib.lib_Node.ln_Type = NT_LIBRARY;
	base->lib.lib_Node.ln_Name = (char *)LibName;
	base->lib.lib_Flags = LIBF_SUMUSED | LIBF_CHANGED;
	base->lib.lib_Version = LibVersion;
	base->lib.lib_Revision = LibRevision;
	base->lib.lib_IdString = (APTR)LibIdString;

	if( __UserLibInit( &base->lib ) != 0 )
	{
		libstart_free( base );
		return( NULL );
	}

	return( &base->lib );
}

ULONG libstart_open_c( struct LibStartBase *base )
{
	base->lib.lib_OpenCnt++;
	base->lib.lib_Flags &= ~LIBF_DELEXP;

	return( (ULONG)&base->lib );
}

ULONG libstart_expunge_c( struct LibStartBase *base )
{
	BPTR seglist;

	if( base->lib.lib_OpenCnt )
	{
		base->lib.lib_Flags |= LIBF_DELEXP;
		return( 0 );
	}

	Remove( &base->lib.lib_Node );

	__UserLibCleanup();

	seglist = base->seglist;
	libstart_free( base );

	return( (ULONG)seglist );
}

ULONG libstart_close_c( struct LibStartBase *base )
{
	if( --base->lib.lib_OpenCnt == 0 && ( base->lib.lib_Flags & LIBF_DELEXP ) )
		return( libstart_expunge_c( base ) );

	return( 0 );
}
