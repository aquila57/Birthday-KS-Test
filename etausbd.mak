OBJ=etausbd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

etausbd:			$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o etausbd $(LDFLAGS)

etausbd.o:			etausbd.c
		$(CC) $(CFLAGS) etausbd.c

clean:
		rm -f $(OBJ) etausbd
