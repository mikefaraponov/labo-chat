#include "constants.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void get(char * from){
	int ok, fd;
	char buffer[BUFFER_SIZE];
	if((fd = open(from, O_RDWR)) == -1){
		perror("Can\'t open fifo");
		exit(1);
	}
	while(1){
		if((ok = read(fd, buffer, BUFFER_SIZE)) == -1){
			perror("Can\'t read from fifo");
			exit(1);
		}
		printf("%s", buffer);
	}
}