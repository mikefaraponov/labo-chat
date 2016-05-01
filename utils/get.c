#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "constants.h"
#include "../listeners/stats.h"

void get(char * from){
	char buffer[BUFFER_SIZE];
	int ok, fd = open(from, O_RDWR);
	assert(fd != -1);
	
	while(1){
		ok = read(fd, buffer, BUFFER_SIZE);
		assert(ok != -1);
		stats[INPUT_CHARS] += strlen(buffer);
		stats[INPUT_MSGS]++;
		printf("%s", buffer);
	}
}