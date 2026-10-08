PREFIX = /usr/local
LIBDIR = lib
INSTALL = install
SED = sed

all:
ifeq ($(OS),Windows_NT)
	$(SED) 's#@@PREFIX@@#$(shell cygpath -m ${PREFIX})#' ffmtcodec.pc.in > ffmtcodec.pc
else
	$(SED) 's#@@PREFIX@@#$(PREFIX)#' ffmtcodec.pc.in > ffmtcodec.pc
endif

install: all
	$(INSTALL) -m 0755 -d '$(DESTDIR)$(PREFIX)/include/ffmtcodec'
	$(INSTALL) -m 0644 include/ffmtcodec/*.h '$(DESTDIR)$(PREFIX)/include/ffmtcodec'
	$(INSTALL) -m 0755 -d '$(DESTDIR)$(PREFIX)/include/ffmtcodec/internal'
	$(INSTALL) -m 0644 include/ffmtcodec/internal/*.h '$(DESTDIR)$(PREFIX)/include/ffmtcodec/internal'
	$(INSTALL) -m 0755 -d '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig'
	$(INSTALL) -m 0644 ffmtcodec.pc '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig'

uninstall:
	$(foreach header,$(wildcard include/ffmtcodec/*.h include/ffmtcodec/internal/*.h),rm -f '$(DESTDIR)$(PREFIX)/$(header)';)
	rm -f '$(DESTDIR)$(PREFIX)/$(LIBDIR)/pkgconfig/ffmtcodec.pc'
	-rmdir '$(DESTDIR)$(PREFIX)/include/ffmtcodec/internal' '$(DESTDIR)$(PREFIX)/include/ffmtcodec' 2>/dev/null || true

.PHONY: all install uninstall

