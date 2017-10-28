main:
	gcc fsync.c -o fsync
install: main
	mkdir -p /usr/loca/bin
	cp fsync /usr/loca/bin

