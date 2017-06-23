CC=c99
CFLAGS=-c -Wall

all: clean insert_int
	./insert_int

insert_int: insert_int.o helper.o
	$(CC) -o insert_int insert_int.o helper.o

insert_int.o:
	$(CC) $(CFLAGS) insert_int.c

helper.o:
	$(CC) $(CFLAGS) helper.c

clean:
	rm -rf *.o insert_int
