# Voyager

A Web Browser for Amiga computers.

Also works on MorphOS and CaOS.

## Requirements

### Amiga 68K

- SAS/C
- To be written

### MorphOS

- To be written

## Building

### SAS/C

Type `smake`

### m68k-amigaos-gcc (cross compile)

With the bebbo toolchain (`m68k-amigaos-gcc`, `vasmm68k_mot`) in `PATH`,
run `make` in the top level directory. This builds `build/V` (stripped) and
`build/V.debug` (with symbols). `make install` also copies it to
`Internet/Voyager/V.gcc`, `make clean` removes the objects.

`make -f makefile.gcc` in `Source/` does the same compile and leaves
`V.amigaos.gcc` and `V.gcc.debug` in `Source/`. `CPU=68030` (or 68040,
68060) selects the CPU, `CROSS=` and `VASM=` the tool names.

`make` also builds the plugins and MimePrefs with GCC: `build/Plugins/`
(`voyager_about.vlib`, `voyager_ssl.vlib`, `Search.VPlug`) and
`build/MimePrefs`, from `aboutstuff/makefile.gcc`, `VSSL/amitls/makefile.gcc`,
`searchplugin/makefile.gcc` and `mimeprefs/makefile.gcc`. The shared library
entry (romtag, Open/Close/Expunge) that SAS/C takes from `lib:libent.o` and
`lib:libinit.o` is `libstart_gcc.c`; each library lists its functions in
`.fd` order in a `LibFuncTable[]`. The AmiTLS SDK headers the SSL plugin
needs are in `VSSL/amitls/include/` (MIT/BSD-2-Clause, from
https://github.com/amigazen/AmiTLS). `make install-plugins` replaces the
SAS/C builds in `Internet/Voyager/Plugins` and `Internet/Voyager/MimePrefs`.

`make dist` builds the release archive `build/Voyager-<version>.lha`: the
`Voyager` drawer from `Internet/Voyager` (icons, docs, buttons, certificates,
MUI classes, libs) with the GCC built `V`, plugins and `MimePrefs`, plus
`Voyager.info` and `V.ReadMe` next to it, like the original V3 archives.
lh5 with level 1 headers, so the Amiga LhA unpacks it. `CManager.library` in
`Libs/` is the shipped binary. `vapor_toolkit.library` is not packaged, nothing
in this tree uses it any more.
