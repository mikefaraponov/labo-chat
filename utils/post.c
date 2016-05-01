#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "../listeners/stats.h"

void post(char * to) {
	char buffer[BUFFER_SIZE];
	int ok, fd = open(to, O_RDWR);

	assert(fd != -1);
	while(1) {
		fgets(buffer, BUFFER_SIZE, stdin);
		ok = write(fd, buffer, strlen(buffer) + 1);
		assert(ok != -1);
		stats[OUTPUT_CHARS] += strlen(buffer);
		stats[OUTPUT_MSGS]++;
	}
}
