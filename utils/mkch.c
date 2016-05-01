#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "constants.h"

/**
 *	@name mkch [make channel(named pipe)]
 *  @params where to position fifofile (usually /tmp/<your-channel>)
 *	@retval void
 */
void mkch(char * path) {
	int ok = mkfifo(path, 0666);
	if(ok == -1 && errno != EEXIST) {
		perror("Error opening/creating fifo");
		exit(1);
	}
}
