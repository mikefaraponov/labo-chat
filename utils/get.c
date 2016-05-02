#include "constants.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>

void get(char * from){
	char buffer[BUFFER_SIZE];
	int ok, fd = open(from, O_RDWR));

	assert(fd != -1);
	while(1){
		ok = read(fd, buffer, BUFFER_SIZE);
		assert(ok != -1);
		printf("%s", buffer);
	}
}