#include <signal.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "libs/chat.h"

int * stats;
pid_t child_pid;

int main(int argc, char *argv[]) {

	int i = 0;
	int stats_size = 4;
	int stats_shm_id = shmget(IPC_PRIVATE, stats_size * sizeof(int), 0666 | IPC_CREAT);
	stats = shmat(stats_shm_id, NULL, 0);

	while(i < stats_size) {
		stats[i++] = 0;
	}

	signal(SIGQUIT, sigquit_listener);
	signal(SIGUSR1, stats_listener);
	signal(SIGUSR2, exit_listener);

	if(argc != 3) {
		puts("Using: Chat <get-from> <post-to>");
		exit(1);
	}

	switch(child_pid = fork()) {
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

	// int status = -1;
	// waitpid(child_pid, &status, WEXITED);

	return 0;
}
