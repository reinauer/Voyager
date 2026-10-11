/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_V_PLUGIN_H
#define _INLINE_V_PLUGIN_H

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

#ifndef V_PLUGIN_BASE_NAME
#define V_PLUGIN_BASE_NAME VPluginBase
#endif /* !V_PLUGIN_BASE_NAME */

#define VPLUG_Query() \
      LP0(0x1e, struct TagItem *, VPLUG_Query ,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_ProcessURLMethod(___url) \
      LP1(0x24, APTR, VPLUG_ProcessURLMethod , STRPTR, ___url, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_GetURLData(___urlhandle) \
      LP1(0x2a, APTR, VPLUG_GetURLData , APTR, ___urlhandle, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_GetURLMIMEType(___urlhandle) \
      LP1(0x30, STRPTR, VPLUG_GetURLMIMEType , APTR, ___urlhandle, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_FreeURLData(___urlhandle) \
      LP1NR(0x36, VPLUG_FreeURLData , APTR, ___urlhandle, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_GetClass(___mimetype) \
      LP1(0x3c, APTR, VPLUG_GetClass , STRPTR, ___mimetype, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_Setup(___functable) \
      LP1(0x42, BOOL, VPLUG_Setup , struct vplug_functable *, ___functable, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_Cleanup() \
      LP0NR(0x48, VPLUG_Cleanup ,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_FinalSetup() \
      LP0NR(0x4e, VPLUG_FinalSetup ,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_Hook_Prefs(___method, ___prefsobj) \
      LP2NR(0x54, VPLUG_Hook_Prefs , ULONG, ___method, d0, struct vplug_prefs *, ___prefsobj, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_GetInfo(___vpluginfo, ___nethandle) \
      LP2(0x5a, BOOL, VPLUG_GetInfo , struct VPlugInfo *, ___vpluginfo, a0, APTR, ___nethandle, a1,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_GetURLDataSize(___urlhandle) \
      LP1(0x60, int, VPLUG_GetURLDataSize , APTR, ___urlhandle, a0,\
      , V_PLUGIN_BASE_NAME)

#define VPLUG_ProcessURLString(___string) \
      LP1(0x66, int, VPLUG_ProcessURLString , STRPTR, ___string, a0,\
      , V_PLUGIN_BASE_NAME)

#endif /* !_INLINE_V_PLUGIN_H */
