#include "constants.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void post(char * to) {
	int ok, fd;
	char buffer[BUFFER_SIZE];

	if((fd = open(to, O_RDWR)) == -1) {
		perror("Can\'t open fifo");
		exit(1);
	}
	
	while(1) {
		fgets(buffer, BUFFER_SIZE, stdin);
		if((ok = write(fd, buffer, strlen(buffer) + 1)) == -1){
			perror("Can\'t write to fifo");
			exit(1);
		}
	}
}