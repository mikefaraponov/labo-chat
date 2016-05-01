#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "../listeners/stats.h"

/**
 * @name post [read bytes from named pipe]
 * @params to {char*} write to file from "to" path 
 * @retval void
 */
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
