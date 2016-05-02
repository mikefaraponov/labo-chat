CC=gcc
CFLAGS=-c -Wall
prefix=/usr/local

all: chat

chat: get.o post.o main.o mkch.o
	$(CC) get.o post.o main.o mkch.o -o Chat

get.o: utils/get.c
	$(CC) $(CFLAGS) utils/get.c

post.o: utils/post.c
	$(CC) $(CFLAGS) utils/post.c

main.o: main.c 
	$(CC) $(CFLAGS) main.c
	
mkch.o: utils/mkch.c
	$(CC) $(CFLAGS) utils/mkch.c

install:
	install -m 0755 Chat $(prefix)/bin

remove:
	rm -r $(prefix)/bin/Chat

clean:
	rm -rf *.o chat