#include <signal.h>
#include <wait.h>
#include "chat.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include "stats.h"
/**
 * shm[0] is number of input chars
 * shm[1] is number of output chars
 * shm[2] is number of input messages
 * shm[3] is number of output messages
 */

int * stats;

void stats_handler(int sig){
	printf("-----------------\n"
				   "Input chars: %d\n"
				   "Output chars: %d\n"
				   "Input messages: %d\n"
				   "Output messages: %d\n"
				   "-----------------\n",
	stats[INPUT_CHARS], stats[OUTPUT_CHARS],
		   stats[INPUT_MSGS], stats[OUTPUT_MSGS]);
}

int main(int argc, char *argv[]) {
	pid_t pid;
	int i = 0;
	int stats_size = 4;
	int shm_id = shmget(IPC_PRIVATE, stats_size * sizeof(int), 0666 | IPC_CREAT);
	stats = shmat(shm_id, NULL, 0);

	while(i < stats_size){
		stats[i++] = 0;
	}

	signal(STATS, stats_handler);

	if(argc != 3) {
		puts("Using: Chat <get-from> <post-to>");
		exit(1);
	}

	switch(pid = fork()) {
		case -1:
			perror("Forking error");
			exit(1);
		case 0:
			mkch(argv[2]);
			post(argv[2]);
			break;
		default:
			mkch(argv[1]);
			get(argv[1]);
	}

	int status = -1;
	waitpid(pid, &status, WEXITED);

	return 0;
}
