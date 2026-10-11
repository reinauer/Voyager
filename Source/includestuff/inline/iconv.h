/* Automatically generated header (sfdc 1.13)! Do not edit! */

#ifndef _INLINE_ICONV_H
#define _INLINE_ICONV_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef LIBRARIES_ICONV_H
#include <libraries/iconv.h>
#endif /* !LIBRARIES_ICONV_H */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef ICONV_BASE_NAME
#define ICONV_BASE_NAME IConvBase
#endif /* !ICONV_BASE_NAME */

#define libiconv_open(___tocode, ___fromcode) \
      LP2(0x1e, iconv_t, libiconv_open , const char *, ___tocode, a0, const char *, ___fromcode, a1,\
      , ICONV_BASE_NAME)

#define libiconv(___cd, ___inbuf, ___inbytesleft, ___outbuf, ___outbytesleft) \
      LP5(0x24, size_t, libiconv , iconv_t, ___cd, a0, const char **, ___inbuf, a1, size_t *, ___inbytesleft, a2, char **, ___outbuf, a3, size_t *, ___outbytesleft, d0,\
      , ICONV_BASE_NAME)

#define libiconv_close(___cd) \
      LP1(0x2a, int, libiconv_close , iconv_t, ___cd, a0,\
      , ICONV_BASE_NAME)

#define libiconvctl(___cd, ___request, ___argument) \
      LP3(0x30, int, libiconvctl , iconv_t, ___cd, a0, int, ___request, d0, void *, ___argument, a1,\
      , ICONV_BASE_NAME)

#define libiconvlist(___do_one, ___data) \
      LP2NR(0x36, libiconvlist , APTR, ___do_one, a0, void *, ___data, a1,\
      , ICONV_BASE_NAME)

#define libiconv_set_relocation_prefix(___orig_prefix, ___curr_prefix) \
      LP2NR(0x3c, libiconv_set_relocation_prefix , const char *, ___orig_prefix, a0, const char *, ___curr_prefix, a1,\
      , ICONV_BASE_NAME)

#define iconv_canonicalize(___name) \
      LP1(0x42, const char *, iconv_canonicalize , const char *, ___name, a0,\
      , ICONV_BASE_NAME)

#endif /* !_INLINE_ICONV_H */
