OBJ=randubd.o

CC=gcc

CFLAGS=-c -Wall -O2

LDFLAGS=-L. -lbd -lgsl -lgslcblas -lm

randubd:			$(OBJ)
		$(CC) -Wall -O2 $(OBJ) -o randubd $(LDFLAGS)

randubd.o:			randubd.c
		$(CC) $(CFLAGS) randubd.c

clean:
		rm -f $(OBJ) randubd
