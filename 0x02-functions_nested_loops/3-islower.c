#include "main.h"

/**
 * _islower- checks if the character is lower
 *
 * return 1 if c is lowercase. 0 otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}

