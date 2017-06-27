CC=c99
CFLAGS=-c -Wall

all: clean main
	./main

main: sortingalgo.o helper.o main.o
	$(CC) -o main main.o sortingalgo.o helper.o

sortingalgo.o:
	$(CC) $(CFLAGS) sortingalgo.c

helper.o:
	$(CC) $(CFLAGS) helper.c

main.o:
	$(CC) $(CFLAGS) main.c

clean:
	rm -rf *.o main
