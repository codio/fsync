main:
	gcc fsync.c -o fsync
install: main
	mkdir -p /usr/local/bin
	cp fsync /usr/local/bin

