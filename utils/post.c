#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include "constants.h"
#include "../listeners/stats.h"
#include "./shared.h"
/**
 * @name post [write bytes to named pipe]
 * @params to {char*} write to file from "to" path 
 * @retval void
 */
void post(char * to) {
	char buffer[BUFFER_SIZE];
	int ok, fd = open(to, O_RDWR);

	assert(fd != -1);

	while(1) {
		fgets(buffer, BUFFER_SIZE, stdin);
		if( strcmp(buffer, STATS_WORD) == 0 ) {
			kill(getpid(), SIGUSR1);
			continue;
		}
		ok = write(fd, buffer, strlen(buffer) + 1);
		assert(ok != -1);
		if( strcmp(buffer, EXIT_WORD) == 0 )
			kill(getpid(), SIGUSR2);
		stats[OUTPUT_CHARS] += letters(buffer);
		stats[OUTPUT_MSGS]++;
	}
}
