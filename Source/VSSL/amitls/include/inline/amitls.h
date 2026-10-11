/* GCC inline macros for amitls.library, generated from amitls_lib.sfd with
 * sfdc --target=m68k-amigaos --mode=macros (the LibDescConverter version
 * shipped in the AmiTLS SDK does not compile with bebbo's gcc). */
/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_AMITLS_H
#define _INLINE_AMITLS_H

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

#ifndef AMITLS_BASE_NAME
#define AMITLS_BASE_NAME TlsBase
#endif /* !AMITLS_BASE_NAME */

#define TlsBaseTagsA(___tags) \
      LP1(0x1e, LONG, TlsBaseTagsA , struct TagItem *, ___tags, a0,\
      , AMITLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define TlsBaseTags(____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; TlsBaseTagsA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define TlsError() \
      LP0(0x24, LONG, TlsError ,\
      , AMITLS_BASE_NAME)

#define TlsGetErrorString(___code) \
      LP1(0x2a, STRPTR, TlsGetErrorString , LONG, ___code, d0,\
      , AMITLS_BASE_NAME)

#define TlsTaskAttach(___SocketBase, ___errno_ptr) \
      LP2(0x30, LONG, TlsTaskAttach , struct Library *, ___SocketBase, a0, APTR, ___errno_ptr, a1,\
      , AMITLS_BASE_NAME)

#define TlsTaskDetach() \
      LP0NR(0x36, TlsTaskDetach ,\
      , AMITLS_BASE_NAME)

#define NewTlsContextA(___tags) \
      LP1(0x3c, struct TlsContext *, NewTlsContextA , struct TagItem *, ___tags, a0,\
      , AMITLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define NewTlsContext(____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; NewTlsContextA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DisposeTlsContext(___ctx) \
      LP1NR(0x42, DisposeTlsContext , struct TlsContext *, ___ctx, a0,\
      , AMITLS_BASE_NAME)

#define SetTlsContextAttrsA(___ctx, ___tags) \
      LP2(0x48, LONG, SetTlsContextAttrsA , struct TlsContext *, ___ctx, a0, struct TagItem *, ___tags, a1,\
      , AMITLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SetTlsContextAttrs(___ctx, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; SetTlsContextAttrsA((___ctx), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define NewTlsConnection(___ctx) \
      LP1(0x4e, struct TlsConnection *, NewTlsConnection , struct TlsContext *, ___ctx, a0,\
      , AMITLS_BASE_NAME)

#define DisposeTlsConnection(___conn) \
      LP1NR(0x54, DisposeTlsConnection , struct TlsConnection *, ___conn, a0,\
      , AMITLS_BASE_NAME)

#define TlsAttachSocketA(___conn, ___sock, ___hostname, ___tags) \
      LP4(0x5a, LONG, TlsAttachSocketA , struct TlsConnection *, ___conn, a0, LONG, ___sock, d0, STRPTR, ___hostname, a1, struct TagItem *, ___tags, a2,\
      , AMITLS_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define TlsAttachSocket(___conn, ___sock, ___hostname, ____tag1, ...) \
    ({_sfdc_vararg _tags[] = { ____tag1, __VA_ARGS__ }; TlsAttachSocketA((___conn), (___sock), (___hostname), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define TlsRead(___conn, ___buffer, ___buflen, ___timeout_secs) \
      LP4(0x60, LONG, TlsRead , struct TlsConnection *, ___conn, a0, APTR, ___buffer, a1, ULONG, ___buflen, d0, ULONG, ___timeout_secs, d1,\
      , AMITLS_BASE_NAME)

#define TlsWrite(___conn, ___buffer, ___len) \
      LP3(0x66, LONG, TlsWrite , struct TlsConnection *, ___conn, a0, APTR, ___buffer, a1, ULONG, ___len, d0,\
      , AMITLS_BASE_NAME)

#define TlsPending(___conn) \
      LP1(0x6c, ULONG, TlsPending , struct TlsConnection *, ___conn, a0,\
      , AMITLS_BASE_NAME)

#define TlsShutdown(___conn) \
      LP1(0x72, LONG, TlsShutdown , struct TlsConnection *, ___conn, a0,\
      , AMITLS_BASE_NAME)

#define TlsGetLastError(___conn) \
      LP1(0x78, LONG, TlsGetLastError , struct TlsConnection *, ___conn, a0,\
      , AMITLS_BASE_NAME)

#define TlsGetCertVerifyDetail(___conn) \
      LP1(0x7e, LONG, TlsGetCertVerifyDetail , struct TlsConnection *, ___conn, a0,\
      , AMITLS_BASE_NAME)

#define TlsGetPeerCert(___conn, ___cert) \
      LP2(0x84, LONG, TlsGetPeerCert , struct TlsConnection *, ___conn, a0, struct TlsPeerCert *, ___cert, a1,\
      , AMITLS_BASE_NAME)

#define TlsPeerCertFree(___cert) \
      LP1NR(0x8a, TlsPeerCertFree , struct TlsPeerCert *, ___cert, a0,\
      , AMITLS_BASE_NAME)

#define TlsLoadCABundle(___path) \
      LP1(0x90, LONG, TlsLoadCABundle , STRPTR, ___path, a0,\
      , AMITLS_BASE_NAME)

#define TlsAddTrustedCert(___data, ___len, ___format) \
      LP3(0x96, LONG, TlsAddTrustedCert , APTR, ___data, a0, ULONG, ___len, d0, ULONG, ___format, d1,\
      , AMITLS_BASE_NAME)

#define TlsClearTrustedCerts() \
      LP0NR(0x9c, TlsClearTrustedCerts ,\
      , AMITLS_BASE_NAME)

#define TlsHandshake(___conn, ___timeout_secs) \
      LP2(0xa2, LONG, TlsHandshake , struct TlsConnection *, ___conn, a0, ULONG, ___timeout_secs, d0,\
      , AMITLS_BASE_NAME)

#endif /* !_INLINE_AMITLS_H */
