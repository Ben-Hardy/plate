C=gcc-4.9
CFLAGS=-Wall -pedantic -std=c99 -O3

executables=plate

plate.o: plate.c
	$(C) $(CFLAGS) plate.c -o plate

clean:
	rm -rf plate

