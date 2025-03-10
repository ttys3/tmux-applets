CC?= gcc
CFLAGS+=-Os
STRIP=strip

PREFIX?= /usr/local
INSTALL?= install
INSTALLDIR= ${INSTALL} -d
INSTALLBIN= ${INSTALL} -m 555
INSTALLMAN= ${INSTALL} -m 444

.PHONY: clean all

all: tmux-cpu-freq tmux-ping tmux-mem tmux-curl

tmux-cpu-freq: tmux-cpu-freq.c
	$(CC) $(CFLAGS) -o tmux-cpu-freq tmux-cpu-freq.c
	$(STRIP) -s tmux-cpu-freq

tmux-ping: tmux-ping.c
	$(CC) $(CFLAGS) -o tmux-ping tmux-ping.c
	$(STRIP) -s tmux-ping

tmux-mem: tmux-mem.c
	$(CC) $(CFLAGS) -o tmux-mem tmux-mem.c
	$(STRIP) -s tmux-mem

tmux-curl: tmux-curl.c
	$(CC) $(CFLAGS) -o tmux-curl tmux-curl.c
	$(STRIP) -s tmux-curl

clean:
	rm -f tmux-cpu-freq
	rm -f tmux-ping
	rm -f tmux-mem
	rm -f tmux-curl

install: all
	${INSTALLDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALLBIN} tmux-cpu-freq ${DESTDIR}${PREFIX}/bin/
	${INSTALLBIN} tmux-ping ${DESTDIR}${PREFIX}/bin/
	${INSTALLBIN} tmux-mem ${DESTDIR}${PREFIX}/bin/
	${INSTALLBIN} tmux-curl ${DESTDIR}${PREFIX}/bin/
