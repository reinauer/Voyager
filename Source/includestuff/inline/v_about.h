/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_V_ABOUT_H
#define _INLINE_V_ABOUT_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef V_ABOUT_BASE_NAME
#define V_ABOUT_BASE_NAME VAboutBase
#endif /* !V_ABOUT_BASE_NAME */

#define VABOUT_GetAboutPtr(___revid, ___owner, ___imgdeclib) \
      LP3(0x1e, STRPTR, VABOUT_GetAboutPtr , STRPTR, ___revid, a0, STRPTR, ___owner, a1, STRPTR, ___imgdeclib, a2,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetVLogo(___sizeptr) \
      LP1(0x24, APTR, VABOUT_GetVLogo , int *, ___sizeptr, a0,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetSSLLogo(___sizeptr) \
      LP1(0x2a, APTR, VABOUT_GetSSLLogo , int *, ___sizeptr, a0,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetPNGLogo(___sizeptr) \
      LP1(0x30, APTR, VABOUT_GetPNGLogo , int *, ___sizeptr, a0,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetAboutIbeta() \
      LP0(0x36, STRPTR, VABOUT_GetAboutIbeta ,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetV3Logo(___sizeptr) \
      LP1(0x3c, APTR, VABOUT_GetV3Logo , int *, ___sizeptr, a0,\
      , V_ABOUT_BASE_NAME)

#define VABOUT_GetFlashLogo(___sizeptr) \
      LP1(0x42, APTR, VABOUT_GetFlashLogo , int *, ___sizeptr, a0,\
      , V_ABOUT_BASE_NAME)

#endif /* !_INLINE_V_ABOUT_H */
