OBJ=sinebd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

sinebd:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o sinebd $(LDFLAGS)

sinebd.o:			sinebd.c
		$(CC) $(CFLAGS) sinebd.c

clean:
		rm -f $(OBJ) sinebd
