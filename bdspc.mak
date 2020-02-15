OBJ=bdspc.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

bdspc:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o bdspc $(LDFLAGS)

bdspc.o:			bdspc.c
		$(CC) $(CFLAGS) bdspc.c

clean:
		rm -f $(OBJ) bdspc
