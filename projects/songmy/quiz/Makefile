CFLAGS= -Wall -fpic -coverage -lm -std=c99

all: testme.o
	./testme

testme.o: testme.c
	gcc -o testme testme.c

clean:
	rm -f *.o testme
