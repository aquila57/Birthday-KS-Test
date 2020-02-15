OBJ=gslbd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

gslbd:				$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o gslbd $(LDFLAGS)

gslbd.o:			gslbd.c
		$(CC) $(CFLAGS) gslbd.c

clean:
		rm -f $(OBJ) gslbd
