# VSSL

Voyager SSL plugin (`PROGDIR:Plugins/voyager_ssl.vlib`). The browser talks only to the `VSSL_*` LVOs in `fd/vssl.fd` (ABI v9). Crypto backends are separate plugins that export that same jump table.

| Directory | Backend | Notes |
| --- | --- | --- |
| `amitls/` | [amitls.library](../../../AmiTLS) (BearSSL) | Current OS3 plugin. `smake` here. |
| `openssl/` | OpenSSL 0.9.2b | Historical; do not ship. |
| *(later)* | AmiSSL | Same `VSSL_*` ABI, different `.vlib` build. |

Runtime for the AmiTLS plugin: `LIBS:amitls.library` (v1, revision 2+ for `TlsHandshake`) and a PEM CA bundle (`PROGDIR:Certificates/cacert.pem` or the other paths listed in `amitls/vssl.c`).

## GCC build

`make -f makefile.gcc` in `amitls/` (or `make plugins` in the top level
directory) builds `amitls/objects/gcc/voyager_ssl.vlib` with
m68k-amigaos-gcc. The library entry comes from `../libstart_gcc.c`, the
function table at the end of `vssl.c` follows `fd/vssl.fd`. The AmiTLS SDK
headers are in `amitls/include/` (MIT or BSD-2-Clause, see
`include/LICENSE.amitls`); `include/inline/amitls.h` was regenerated from
`amitls_lib.sfd` with `sfdc --mode=macros` because the SDK's inline file does
not compile with GCC 13.
