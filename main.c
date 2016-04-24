#include "chat.h"

int main(int argc, char *argv[]) {
	pid_t pid;

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

	return 0;
}