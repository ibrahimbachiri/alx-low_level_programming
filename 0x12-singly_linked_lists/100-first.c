#include <stdio.h>

void print_before_main(void) __attribute__ ((constructor));

/**
 * print_before_main - Function to be executed before the main function
 */
void print_before_main(void)
{
	char *msg = "You're beat! and yet, you must allow,\n"
		    "I bore my house upon my back!\n";

	printf("%s", msg);
}
