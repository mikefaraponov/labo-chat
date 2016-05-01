#include <stdio.h>
#include "stats.h"

void stats_listener(int sig) {
	printf(
		"\n-----------------\n"
		"Input chars: %d\n"
		"Output chars: %d\n"
		"Input messages: %d\n"
		"Output messages: %d\n"
		"-----------------\n",
		stats[INPUT_CHARS], 
		stats[OUTPUT_CHARS],
		stats[INPUT_MSGS], 
		stats[OUTPUT_MSGS]
	);
}
