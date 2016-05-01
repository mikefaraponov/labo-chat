#include <signal.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "libs/chat.h"

int * stats;
pid_t child_pid;

int main(int argc, char *argv[]) {

	if(argc != 3) {
		puts("Using: Chat <get-from> <post-to>");
		exit(EXIT_FAILURE);
	}

	register int i = 0;

	int stats_size = 4,
		stats_shm_size = stats_size * sizeof(int),
		stats_shm_id = shmget(IPC_PRIVATE, stats_shm_size, 0666 | IPC_CREAT);
	
	stats = shmat(stats_shm_id, NULL, 0);

	while(i < stats_size) {
		stats[i++] = 0;
	}

	signal(SIGQUIT, sigquit_listener);
	signal(SIGUSR1, stats_listener);
	signal(SIGUSR2, exit_listener);



	switch(child_pid = fork()) {
		case -1:
			perror("Forking error");
			exit(EXIT_FAILURE);
		case 0:
			mkch(argv[2]);
			post(argv[2]);
			break;
		default:
			mkch(argv[1]);
			get(argv[1]);
	}

	return EXIT_SUCCESS;
}
