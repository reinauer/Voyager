/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_VSSL_H
#define _INLINE_VSSL_H

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

#ifndef VSSL_BASE_NAME
#define VSSL_BASE_NAME VSSLBase
#endif /* !VSSL_BASE_NAME */

#define VSSL_Id() \
      LP0(0x1e, char *, VSSL_Id ,\
      , VSSL_BASE_NAME)

#define VSSL_Create_CTX() \
      LP0(0x24, APTR, VSSL_Create_CTX ,\
      , VSSL_BASE_NAME)

#define VSSL_Free_CTX(___ctx) \
      LP1NR(0x2a, VSSL_Free_CTX , APTR, ___ctx, a0,\
      , VSSL_BASE_NAME)

#define VSSL_Connect(___ctx, ___sock) \
      LP2(0x30, APTR, VSSL_Connect , APTR, ___ctx, a0, int, ___sock, d0,\
      , VSSL_BASE_NAME)

#define VSSL_Close(___ssl) \
      LP1NR(0x36, VSSL_Close , APTR, ___ssl, a0,\
      , VSSL_BASE_NAME)

#define VSSL_GetCipher(___ssl) \
      LP1(0x3c, char *, VSSL_GetCipher , APTR, ___ssl, a0,\
      , VSSL_BASE_NAME)

#define VSSL_Write(___ssl, ___buff, ___len) \
      LP3(0x42, int, VSSL_Write , APTR, ___ssl, a0, APTR, ___buff, a1, int, ___len, d0,\
      , VSSL_BASE_NAME)

#define VSSL_Read(___ssl, ___buff, ___len) \
      LP3(0x48, int, VSSL_Read , APTR, ___ssl, a0, APTR, ___buff, a1, int, ___len, d0,\
      , VSSL_BASE_NAME)

#define VSSL_SetTCPMode(___mode, ___arg) \
      LP2NR(0x4e, VSSL_SetTCPMode , int, ___mode, d0, APTR, ___arg, a0,\
      , VSSL_BASE_NAME)

#define VSSL_GetPeerCertificate(___ssl) \
      LP1(0x54, X509 *, VSSL_GetPeerCertificate , APTR, ___ssl, a0,\
      , VSSL_BASE_NAME)

#define VSSL_AddCertDir(___ctx, ___dir) \
      LP2NR(0x5a, VSSL_AddCertDir , APTR, ___ctx, a0, STRPTR, ___dir, a1,\
      , VSSL_BASE_NAME)

#define VSSL_X509_Free(___cert) \
      LP1NR(0x60, VSSL_X509_Free , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_NameOneline(___name) \
      LP1(0x66, STRPTR, VSSL_X509_NameOneline , X509_NAME *, ___name, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_FreeNameOneline(___name) \
      LP1NR(0x6c, VSSL_X509_FreeNameOneline , STRPTR, ___name, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_get_subject_name(___cert) \
      LP1(0x72, X509_NAME *, VSSL_X509_get_subject_name , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_get_issuer_name(___cert) \
      LP1(0x78, X509_NAME *, VSSL_X509_get_issuer_name , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_get_notBefore(___cert) \
      LP1(0x7e, ASN1_UTCTIME *, VSSL_X509_get_notBefore , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_get_notAfter(___cert) \
      LP1(0x84, ASN1_UTCTIME *, VSSL_X509_get_notAfter , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_GetVerifyResult(___ssl, ___errorp) \
      LP2(0x8a, int, VSSL_GetVerifyResult , APTR, ___ssl, a0, char **, ___errorp, a1,\
      , VSSL_BASE_NAME)

#define VSSL_WriteCertPEM(___cert, ___outfile) \
      LP2(0x90, int, VSSL_WriteCertPEM , X509 *, ___cert, a0, STRPTR, ___outfile, a1,\
      , VSSL_BASE_NAME)

#define VSSL_ReadCertPEM(___filename) \
      LP1(0x96, X509 *, VSSL_ReadCertPEM , STRPTR, ___filename, a0,\
      , VSSL_BASE_NAME)

#define VSSL_ReadCertASN1(___filename) \
      LP1(0x9c, X509 *, VSSL_ReadCertASN1 , STRPTR, ___filename, a0,\
      , VSSL_BASE_NAME)

#define VSSL_ASN1_UTCTIME_sprint(___to, ___tm) \
      LP2NR(0xa2, VSSL_ASN1_UTCTIME_sprint , char *, ___to, a0, ASN1_UTCTIME *, ___tm, a1,\
      , VSSL_BASE_NAME)

#define VSSL_X509_NameHash(___cert) \
      LP1(0xa8, ULONG, VSSL_X509_NameHash , X509 *, ___cert, a0,\
      , VSSL_BASE_NAME)

#define VSSL_X509_HaveSubjectCert(___ctx, ___cert) \
      LP2(0xae, int, VSSL_X509_HaveSubjectCert , APTR, ___ctx, a0, X509 *, ___cert, a1,\
      , VSSL_BASE_NAME)

#define VSSL_X509_fingerprint(___cert, ___to) \
      LP2(0xb4, int, VSSL_X509_fingerprint , X509 *, ___cert, a0, char *, ___to, a1,\
      , VSSL_BASE_NAME)

#define VSSL_X509_serialnumber(___cert, ___to) \
      LP2NR(0xba, VSSL_X509_serialnumber , X509 *, ___cert, a0, char *, ___to, a1,\
      , VSSL_BASE_NAME)

#define VSSL_SetRandSeed(___buff, ___len) \
      LP2NR(0xc0, VSSL_SetRandSeed , APTR, ___buff, a0, int, ___len, d0,\
      , VSSL_BASE_NAME)

#define VSSL_GetStats(___ctx, ___ci) \
      LP2NR(0xc6, VSSL_GetStats , APTR, ___ctx, a0, struct VSSL_CacheInfo *, ___ci, a1,\
      , VSSL_BASE_NAME)

#define VSSL_CTX_Set_Options(___ctx, ___options) \
      LP2NR(0xcc, VSSL_CTX_Set_Options , APTR, ___ctx, a0, ULONG, ___options, d0,\
      , VSSL_BASE_NAME)

#define VSSL_GetVersion(___ssl) \
      LP1(0xd2, STRPTR, VSSL_GetVersion , APTR, ___ssl, a0,\
      , VSSL_BASE_NAME)

#define VSSL_SetDefaultOptions(___options) \
      LP1NR(0xd8, VSSL_SetDefaultOptions , ULONG, ___options, d0,\
      , VSSL_BASE_NAME)

#define VSSL_ConnectHost(___ctx, ___sock, ___hostname) \
      LP3(0xde, APTR, VSSL_ConnectHost , APTR, ___ctx, a0, int, ___sock, d0, STRPTR, ___hostname, a1,\
      , VSSL_BASE_NAME)

#define VSSL_Pending(___ssl) \
      LP1(0xe4, ULONG, VSSL_Pending , APTR, ___ssl, a0,\
      , VSSL_BASE_NAME)

#endif /* !_INLINE_VSSL_H */
