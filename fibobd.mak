OBJ=fibobd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

fibobd:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o fibobd $(LDFLAGS)

fibobd.o:			fibobd.c
		$(CC) $(CFLAGS) fibobd.c

clean:
		rm -f $(OBJ) fibobd
