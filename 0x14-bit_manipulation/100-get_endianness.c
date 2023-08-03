#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian = (char *)&num;

	/* If the least significant byte (first byte) is 1, system is little endian */
	return (*endian);
}
