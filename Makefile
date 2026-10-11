# Top level makefile: cross compile Voyager with m68k-amigaos-gcc
#
# make            builds Voyager into build/V (plus build/V.debug with symbols)
# make install    also copies V into Internet/Voyager/V.gcc
# make clean
#
# The compile itself is done by Source/makefile.gcc. The SAS/C build
# (smake in Source/) is unaffected.

CROSS ?= m68k-amigaos-
CPU   ?= 68020
VASM  ?= vasmm68k_mot

BUILDDIR = build
SRCDIR   = Source

SUBMAKE = $(MAKE) -C $(SRCDIR) -f makefile.gcc CROSS=$(CROSS) CPU=$(CPU) VASM=$(VASM)

.PHONY: all voyager check-toolchain install clean

all: $(BUILDDIR)/V

check-toolchain:
	@command -v $(CROSS)gcc >/dev/null 2>&1 || \
		{ echo "$(CROSS)gcc not found in PATH"; exit 1; }
	@command -v $(VASM) >/dev/null 2>&1 || \
		{ echo "$(VASM) not found in PATH"; exit 1; }

voyager: check-toolchain
	$(SUBMAKE)

$(BUILDDIR)/V: voyager
	@mkdir -p $(BUILDDIR)
	cp $(SRCDIR)/V.amigaos.gcc $@
	cp $(SRCDIR)/V.gcc.debug $(BUILDDIR)/V.debug

install: all
	cp $(BUILDDIR)/V Internet/Voyager/V.gcc

clean:
	$(SUBMAKE) clean
	rm -rf $(BUILDDIR)
