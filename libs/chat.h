#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define GET_FROM 1
#define POST_TO 2

void mkch(char * path);
void get(char * from);
void post(char * to);