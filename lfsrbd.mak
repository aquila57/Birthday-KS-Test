OBJ=lfsrbd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

lfsrbd:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o lfsrbd $(LDFLAGS)

lfsrbd.o:			lfsrbd.c
		$(CC) $(CFLAGS) lfsrbd.c

clean:
		rm -f $(OBJ) lfsrbd
