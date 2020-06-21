# polygonwm - polygonal window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c polygonwm.c util.c
OBJ = ${SRC:.c=.o}

all: options polygonwm

options:
	@echo polygonwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

polygonwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f polygonwm ${OBJ} polygonwm-${VERSION}.tar.gz

dist: clean
	mkdir -p polygonwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		 drw.h util.h ${SRC} vtransient.c polygonwm-${VERSION}
	tar -cf polygonwm-${VERSION}.tar polygonwm-${VERSION}
	gzip polygonw-${VERSION}.tar
	rm -rf polygonwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f polygonwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/polygonwm

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/polygonwm

.PHONY: all options clean dist install uninstall
