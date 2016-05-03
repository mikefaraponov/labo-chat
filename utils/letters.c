#include <ctype.h>
#include <string.h>

/**
 * @name letters
 * @description return number of letters in the string
 * @params str {char*}
 * @retval {int}
 */
int letters(char * str) {
	register int i = 0, result = 0;
	for(; i < strlen(str); i++)
		if(isalpha(str[i])) result++;
	return result;
}