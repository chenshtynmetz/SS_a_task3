CC=gcc
AR=ar
FLAGS= -Wall -g

all: stringProg 
stringProg: main.o stringProg.o 
	$(CC) $(FLAGS) -o stringProg main.o stringProg.o
main.o: main.c stringProg.h 
	$(CC) $(FLAGS) -c main.c
stringProg.o: stringProg.c
	$(CC) $(FLAGS) -c stringProg.c
.PHONY: clean all
clean:
	rm -f *.o *.so mains