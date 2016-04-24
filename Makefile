CC=gcc
CFLAGS=-c -Wall
prefix=/usr/local

all: chat

chat: get.o post.o main.o mkch.o
	$(CC) get.o post.o main.o mkch.o -o Chat

get.o: get.c
	$(CC) $(CFLAGS) get.c

post.o: post.c
	$(CC) $(CFLAGS) post.c

main.o: main.c 
	$(CC) $(CFLAGS) main.c

mkch.o: mkch.c
	$(CC) $(CFLAGS) mkch.c

install:
	install -m 0755 Chat $(prefix)/bin

remove:
	rm -r $(prefix)/bin/Chat

clean:
	rm -rf *.o chat