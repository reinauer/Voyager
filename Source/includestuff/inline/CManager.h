/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_CMANAGER_H
#define _INLINE_CMANAGER_H

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

#ifndef CMANAGER_BASE_NAME
#define CMANAGER_BASE_NAME CManagerBase
#endif /* !CMANAGER_BASE_NAME */

#define CM_StartManager(___file, ___pubscreen) \
      LP2(0x1e, APTR, CM_StartManager , STRPTR, ___file, a0, STRPTR, ___pubscreen, a1,\
      , CMANAGER_BASE_NAME)

#define CM_LoadDataOld(___prefs, ___data, ___user) \
      LP3(0x24, BOOL, CM_LoadDataOld , STRPTR, ___prefs, a0, struct CMDataOld *, ___data, a1, STRPTR, ___user, a2,\
      , CMANAGER_BASE_NAME)

#define CM_SaveDataOld(___prefs, ___data, ___user) \
      LP3NR(0x2a, CM_SaveDataOld , STRPTR, ___prefs, a0, struct CMDataOld *, ___data, a1, STRPTR, ___user, a2,\
      , CMANAGER_BASE_NAME)

#define CM_FreeDataOld(___data) \
      LP1NR(0x30, CM_FreeDataOld , struct CMDataOld *, ___data, a0,\
      , CMANAGER_BASE_NAME)

#define CM_GetParent(___list, ___current) \
      LP2(0x36, struct CMGroup *, CM_GetParent , struct CMGroup *, ___list, a0, struct CMGroup *, ___current, a1,\
      , CMANAGER_BASE_NAME)

#define CM_AllocEntry(___type) \
      LP1(0x3c, APTR, CM_AllocEntry , ULONG, ___type, d0,\
      , CMANAGER_BASE_NAME)

#define CM_FreeEntry(___entry) \
      LP1NR(0x42, CM_FreeEntry , APTR, ___entry, a0,\
      , CMANAGER_BASE_NAME)

#define CM_FreeHandle(___handle, ___close) \
      LP2NR(0x48, CM_FreeHandle , APTR, ___handle, a0, BOOL, ___close, d0,\
      , CMANAGER_BASE_NAME)

#define CM_GetEntry(___handle, ___flags) \
      LP2(0x4e, APTR, CM_GetEntry , APTR, ___handle, a0, ULONG, ___flags, d0,\
      , CMANAGER_BASE_NAME)

#define CM_CreateBitMap(___width, ___height, ___depth, ___flags, ___friend) \
      LP5(0x54, struct BitMap *, CM_CreateBitMap , ULONG, ___width, d0, ULONG, ___height, d1, ULONG, ___depth, d2, ULONG, ___flags, d3, struct BitMap *, ___friend, a0,\
      , CMANAGER_BASE_NAME)

#define CM_DeleteBitMap(___bitmap) \
      LP1NR(0x5a, CM_DeleteBitMap , struct BitMap *, ___bitmap, a0,\
      , CMANAGER_BASE_NAME)

#define CM_AddEntry(___entry) \
      LP1(0x60, BOOL, CM_AddEntry , APTR, ___entry, a0,\
      , CMANAGER_BASE_NAME)

#define CM_FreeList(___list) \
      LP1NR(0x66, CM_FreeList , struct MinList *, ___list, a0,\
      , CMANAGER_BASE_NAME)

#define CM_LoadCurrentUserData(___askuser) \
      LP1(0x6c, struct CMData *, CM_LoadCurrentUserData , BOOL, ___askuser, d0,\
      , CMANAGER_BASE_NAME)

#define CM_LoadData(___prefs, ___data, ___user) \
      LP3(0x72, BOOL, CM_LoadData , STRPTR, ___prefs, a0, struct CMData *, ___data, a1, STRPTR, ___user, a2,\
      , CMANAGER_BASE_NAME)

#define CM_SaveData(___prefs, ___data, ___user) \
      LP3NR(0x78, CM_SaveData , STRPTR, ___prefs, a0, struct CMData *, ___data, a1, STRPTR, ___user, a2,\
      , CMANAGER_BASE_NAME)

#define CM_FreeData(___data) \
      LP1NR(0x7e, CM_FreeData , struct CMData *, ___data, a0,\
      , CMANAGER_BASE_NAME)

#define CM_AllocCMData() \
      LP0(0x84, struct CMData *, CM_AllocCMData ,\
      , CMANAGER_BASE_NAME)

#define CM_GetString(___id) \
      LP1(0x8a, STRPTR, CM_GetString , ULONG, ___id, d0,\
      , CMANAGER_BASE_NAME)

#endif /* !_INLINE_CMANAGER_H */
