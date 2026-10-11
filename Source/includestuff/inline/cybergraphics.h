#ifndef VOYAGER_INLINE_CYBERGRAPHICS_H
#define VOYAGER_INLINE_CYBERGRAPHICS_H
/*
 * GCC inlines: the toolchain's cybergraphics inlines plus the
 * cybergraphics.library V43 calls it does not have
 * (see pragmas/cybergraphics_pragmas.h).
 */

#include_next <inline/cybergraphics.h>

#ifndef WritePixelArrayAlpha
#define WritePixelArrayAlpha(___srcRect, ___SrcX, ___SrcY, ___SrcMod, ___RastPort, ___DestX, ___DestY, ___SizeX, ___SizeY, ___globalAlpha) \
      LP10(0xd8, ULONG, WritePixelArrayAlpha , APTR, ___srcRect, a0, UWORD, ___SrcX, d0, UWORD, ___SrcY, d1, UWORD, ___SrcMod, d2, struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d3, UWORD, ___DestY, d4, UWORD, ___SizeX, d5, UWORD, ___SizeY, d6, ULONG, ___globalAlpha, d7,\
      , CYBERGRAPHICS_BASE_NAME)
#endif

#endif /* VOYAGER_INLINE_CYBERGRAPHICS_H */
