CC=gcc
CFLAGS=-c -Wall
prefix=/usr/local

all: chat

chat: get.o post.o main.o mkch.o exit.o stats.o letters.o
	$(CC) get.o post.o main.o mkch.o exit.o stats.o letters.o -o Chat

letters.o: utils/letters.c
	$(CC) $(CFLAGS) utils/letters.c

get.o: utils/get.c
	$(CC) $(CFLAGS) utils/get.c

post.o: utils/post.c
	$(CC) $(CFLAGS) utils/post.c

main.o: main.c 
	$(CC) $(CFLAGS) main.c

mkch.o: utils/mkch.c
	$(CC) $(CFLAGS) utils/mkch.c


exit.o: listeners/exit.c
	$(CC) $(CFLAGS) listeners/exit.c

stats.o: listeners/stats.c
	$(CC) $(CFLAGS) listeners/stats.c

install:
	install -m 0755 Chat $(prefix)/bin

remove:
	rm -r $(prefix)/bin/Chat

clean:
	rm -rf *.o chat