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
