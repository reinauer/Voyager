/* Automatically generated header (sfdc 1.13)! Do not edit! */
#ifndef PRAGMAS_CMANAGER_PRAGMAS_H
#define PRAGMAS_CMANAGER_PRAGMAS_H

/*
**   $VER: CManager_pragmas.h 10.2 $Id: CManager_lib.sfd,v 10.2 (offsets from ppcinline/CManager.h) $
**
**   Direct ROM interface (pragma) definitions.
**
**   Copyright (c) 2001 Amiga, Inc.
**       All Rights Reserved
*/

#if defined(LATTICE) || defined(__SASC) || defined(_DCC)
#ifndef __CLIB_PRAGMA_LIBCALL
#define __CLIB_PRAGMA_LIBCALL
#endif /* __CLIB_PRAGMA_LIBCALL */
#else /* __MAXON__, __STORM__ or AZTEC_C */
#ifndef __CLIB_PRAGMA_AMICALL
#define __CLIB_PRAGMA_AMICALL
#endif /* __CLIB_PRAGMA_AMICALL */
#endif /* */

#if defined(__SASC_60) || defined(__STORM__)
#ifndef __CLIB_PRAGMA_TAGCALL
#define __CLIB_PRAGMA_TAGCALL
#endif /* __CLIB_PRAGMA_TAGCALL */
#endif /* __MAXON__, __STORM__ or AZTEC_C */

#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_StartManager 1e 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x1e, CM_StartManager(a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_LoadDataOld 24 a9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x24, CM_LoadDataOld(a0,a1,a2))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_SaveDataOld 2a a9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x2a, CM_SaveDataOld(a0,a1,a2))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_FreeDataOld 30 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x30, CM_FreeDataOld(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_GetParent 36 9802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x36, CM_GetParent(a0,a1))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_AllocEntry 3c 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x3c, CM_AllocEntry(d0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_FreeEntry 42 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x42, CM_FreeEntry(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_FreeHandle 48 0802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x48, CM_FreeHandle(a0,d0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_GetEntry 4e 0802
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x4e, CM_GetEntry(a0,d0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_CreateBitMap 54 8321005
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x54, CM_CreateBitMap(d0,d1,d2,d3,a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_DeleteBitMap 5a 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x5a, CM_DeleteBitMap(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_AddEntry 60 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x60, CM_AddEntry(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_FreeList 66 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x66, CM_FreeList(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_LoadCurrentUserData 6c 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x6c, CM_LoadCurrentUserData(d0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_LoadData 72 a9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x72, CM_LoadData(a0,a1,a2))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_SaveData 78 a9803
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x78, CM_SaveData(a0,a1,a2))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_FreeData 7e 801
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x7e, CM_FreeData(a0))
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_AllocCMData 84 00
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x84, CM_AllocCMData())
#endif /* __CLIB_PRAGMA_AMICALL */
#ifdef __CLIB_PRAGMA_LIBCALL
 #pragma libcall CManagerBase CM_GetString 8a 001
#endif /* __CLIB_PRAGMA_LIBCALL */
#ifdef __CLIB_PRAGMA_AMICALL
 #pragma amicall(CManagerBase, 0x8a, CM_GetString(d0))
#endif /* __CLIB_PRAGMA_AMICALL */

#endif /* PRAGMAS_CMANAGER_PRAGMAS_H */
