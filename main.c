#include "libs/chat.h"

int main(int argc, char *argv[]) {
	pid_t child_pid;

	if(argc != 3) {
		puts("Using: Chat <get-from> <post-to>");
		exit(1);
	}

	switch(child_pid = fork()) {
		case -1:
			perror("Forking error");
			exit(1);
		case 0:
			mkch(argv[POST_TO]);
			post(argv[POST_TO]);
			break;
		default:
			mkch(argv[GET_FROM]);
			get(argv[GET_FROM]);
	}

	return 0;
}