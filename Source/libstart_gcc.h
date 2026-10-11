/*
 * Shared library entry for the 68k GCC (libnix) builds of the Voyager
 * plugins (voyager_about.vlib, voyager_ssl.vlib, Search.VPlug).
 * Replaces SAS/C's lib:libent.o + lib:libinit.o, see libstart_gcc.c.
 *
 * A library using it provides:
 *
 *   const char  LibName[];        "voyager_about.vlib"
 *   const char  LibIdString[];    "voyager_about.vlib 4.5 (23.6.2003)\r\n"
 *   const UWORD LibVersion, LibRevision;
 *   const APTR  LibFuncTable[] = { LIBSTART_SYSFUNCS, func1, ..., (APTR)-1 };
 *   long __UserLibInit( struct Library *libbase );  0 = success
 *   void __UserLibCleanup( void );
 *
 * libstart_gcc.c is compiled with -DLIB_VERSION=<n> (the romtag version),
 * linked first and the library is linked with -nostartfiles.
 */

#ifndef LIBSTART_GCC_H
#define LIBSTART_GCC_H

#include <exec/types.h>
#include <exec/libraries.h>

/* assembler stubs in libstart_gcc.c, the first four library vectors */
extern void libstart_open( void );
extern void libstart_close( void );
extern void libstart_expunge( void );
extern void libstart_extfunc( void );

#define LIBSTART_SYSFUNCS \
	(APTR)libstart_open, (APTR)libstart_close, \
	(APTR)libstart_expunge, (APTR)libstart_extfunc

extern const char LibName[];
extern const char LibIdString[];
extern const UWORD LibVersion;
extern const UWORD LibRevision;
extern const APTR LibFuncTable[];

long __UserLibInit( struct Library *libbase );
void __UserLibCleanup( void );

#endif /* LIBSTART_GCC_H */
