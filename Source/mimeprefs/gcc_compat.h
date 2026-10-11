/*
 * SAS/C <constructor.h> replacement for the 68k GCC (libnix) build of
 * MimePrefs.
 *
 * CONSTRUCTOR_P( name, pri ) and DESTRUCTOR_P( name, pri ) register the
 * function with its priority through a libnix init list entry, and
 * gcc_startup.c runs them around mimeprefs_main() the way SAS/C does:
 * constructors by ascending priority (a non-zero return aborts the
 * program with that return code), destructors by descending priority.
 */

#ifndef MIMEPREFS_GCC_COMPAT_H
#define MIMEPREFS_GCC_COMPAT_H

#include <stabs.h>

typedef int (*gcc_ctor_fn)( void );
typedef void (*gcc_dtor_fn)( void );

void gcc_add_constructor( gcc_ctor_fn fn, int pri );
void gcc_add_destructor( gcc_dtor_fn fn, int pri );

#define CONSTRUCTOR_P( name, pri ) \
	static int name##_constructor( void ); \
	void name##_constructor_reg( void ) { gcc_add_constructor( name##_constructor, pri ); } \
	ADD2INIT( name##_constructor_reg, 0 ); \
	static int name##_constructor( void )

#define DESTRUCTOR_P( name, pri ) \
	static void name##_destructor( void ); \
	void name##_destructor_reg( void ) { gcc_add_destructor( name##_destructor, pri ); } \
	ADD2INIT( name##_destructor_reg, 0 ); \
	static void name##_destructor( void )

#endif /* MIMEPREFS_GCC_COMPAT_H */
