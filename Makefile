# Top level makefile: cross compile Voyager with m68k-amigaos-gcc
#
# make            builds build/V (plus build/V.debug with symbols), the
#                 plugins build/Plugins/{voyager_about.vlib,voyager_ssl.vlib,
#                 Search.VPlug} and build/MimePrefs
# make voyager    only the browser, make plugins / make mimeprefs the rest
# make dist       builds the release archive build/Voyager-<version>.lha
#                 (the Voyager drawer like the original V3 archives, see dist)
# make install    copies V into Internet/Voyager/V.gcc
# make install-plugins
#                 replaces Internet/Voyager/Plugins/* and MimePrefs with
#                 the GCC builds (the tree ships the SAS/C builds)
# make clean
#
# The compile itself is done by the makefile.gcc in each source directory.
# The SAS/C builds (smake) are unaffected.

CROSS ?= m68k-amigaos-
CPU   ?= 68020
VASM  ?= vasmm68k_mot
LHA   ?= lha

BUILDDIR = build
SRCDIR   = Source
DISTDIR  = $(BUILDDIR)/dist
VERSION := $(shell awk -F'"' '/^\#define VERSIONSTRING/ { print $$2 }' $(SRCDIR)/rev.h)
DISTLHA  = $(BUILDDIR)/Voyager-$(VERSION).lha

SUBMAKE  = $(MAKE) -f makefile.gcc CROSS=$(CROSS) CPU=$(CPU) VASM=$(VASM)

PLUGINDIRS = $(SRCDIR)/aboutstuff $(SRCDIR)/VSSL/amitls $(SRCDIR)/searchplugin
PLUGINS    = $(BUILDDIR)/Plugins/voyager_about.vlib \
	$(BUILDDIR)/Plugins/voyager_ssl.vlib \
	$(BUILDDIR)/Plugins/Search.VPlug

.PHONY: all voyager plugins mimeprefs check-toolchain install install-plugins \
	dist clean

all: $(BUILDDIR)/V plugins mimeprefs

check-toolchain:
	@command -v $(CROSS)gcc >/dev/null 2>&1 || \
		{ echo "$(CROSS)gcc not found in PATH"; exit 1; }
	@command -v $(VASM) >/dev/null 2>&1 || \
		{ echo "$(VASM) not found in PATH"; exit 1; }

voyager: check-toolchain
	$(SUBMAKE) -C $(SRCDIR)

$(BUILDDIR)/V: voyager
	@mkdir -p $(BUILDDIR)
	cp $(SRCDIR)/V.amigaos.gcc $@
	cp $(SRCDIR)/V.gcc.debug $(BUILDDIR)/V.debug

plugins: check-toolchain
	$(SUBMAKE) -C $(SRCDIR)/aboutstuff
	$(SUBMAKE) -C $(SRCDIR)/VSSL/amitls
	$(SUBMAKE) -C $(SRCDIR)/searchplugin
	@mkdir -p $(BUILDDIR)/Plugins
	cp $(SRCDIR)/aboutstuff/objects/gcc/voyager_about.vlib $(BUILDDIR)/Plugins/
	cp $(SRCDIR)/VSSL/amitls/objects/gcc/voyager_ssl.vlib $(BUILDDIR)/Plugins/
	cp $(SRCDIR)/searchplugin/objects/gcc/Search.VPlug $(BUILDDIR)/Plugins/

mimeprefs: check-toolchain
	$(SUBMAKE) -C $(SRCDIR)/mimeprefs
	@mkdir -p $(BUILDDIR)
	cp $(SRCDIR)/mimeprefs/objects/gcc/MimePrefs $(BUILDDIR)/MimePrefs

install: $(BUILDDIR)/V
	cp $(BUILDDIR)/V Internet/Voyager/V.gcc

install-plugins: plugins mimeprefs
	cp $(PLUGINS) Internet/Voyager/Plugins/
	cp $(BUILDDIR)/MimePrefs Internet/Voyager/MimePrefs

# Release archive. Internet/Voyager is the installed drawer (icons, docs,
# buttons, certificates, MUI classes, libs); the binaries built here replace
# the SAS/C ones; vapor_toolkit.library is left out, nothing uses it any
# more. Layout like the original V3 archives: the Voyager drawer with its
# icon and the ReadMe next to it. lh5 with level 1 headers for the Amiga LhA.
dist: all
	rm -rf $(DISTDIR) $(DISTLHA)
	mkdir -p $(DISTDIR)/Voyager
	cp -R Internet/Voyager/. $(DISTDIR)/Voyager/
	cp Internet/Voyager.info $(DISTDIR)/Voyager.info
	rm -f $(DISTDIR)/Voyager/V $(DISTDIR)/Voyager/V.original \
		$(DISTDIR)/Voyager/V.gcc $(DISTDIR)/Voyager/MimePrefs \
		$(DISTDIR)/Voyager/Plugins/*
	rm -f $(DISTDIR)/Voyager/Libs/vapor_toolkit.library
	find $(DISTDIR) -name .DS_Store -delete
	cp $(BUILDDIR)/V $(DISTDIR)/Voyager/V
	cp $(PLUGINS) $(DISTDIR)/Voyager/Plugins/
	cp $(BUILDDIR)/MimePrefs $(DISTDIR)/Voyager/MimePrefs
	cp Internet/Voyager/V.ReadMe Internet/Voyager/V.ReadMe.info $(DISTDIR)/
	cd $(DISTDIR) && $(LHA) -aq2o51 --ignore-mac-files ../$(notdir $(DISTLHA)) \
		Voyager Voyager.info V.ReadMe V.ReadMe.info
	$(LHA) -t $(DISTLHA) >/dev/null
	@echo "built $(DISTLHA)"

clean:
	$(SUBMAKE) -C $(SRCDIR) clean
	for d in $(PLUGINDIRS) $(SRCDIR)/mimeprefs; do $(SUBMAKE) -C $$d clean; done
	rm -rf $(BUILDDIR)
