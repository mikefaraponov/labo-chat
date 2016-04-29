#include "constants.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>

void mkch(char * path) {
	int ok = mkfifo(path, 0666);
	if(ok == -1 && errno != EEXIST) {
		perror("Error opening/creating fifo");
		exit(1);
	}
}
