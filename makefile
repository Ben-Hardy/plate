C=gcc
CFLAGS=-Wall -pedantic -std=c99 -O3

executables=plate

plate: plate.o
	$(C) $(CFLAGS) plate.o -o plate

plate.o: plate.c
	$(C) $(CFLAGS) -c plate.c

clean:
	rm -rf plate plate.o

