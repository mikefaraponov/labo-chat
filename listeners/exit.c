#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "exit.h"

void exit_listener(int sig) {
	kill(child_pid? child_pid : getppid(), SIGQUIT);
	exit(0);
}

void sigquit_listener(int sig) {
	// exit without quit message
	exit(0);
}