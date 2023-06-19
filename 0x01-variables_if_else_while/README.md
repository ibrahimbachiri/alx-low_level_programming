0-positive_or_negative

this code provide how store a different number in the
variable n by invoking the function srand(time(0) which
refered to set random number each time we excute the program

#############################################################
1-last_digit.c

this code provide how store a different number in the
variable n by invoking the function srand(time(0) which
refered to set random number each time we excute the program
and gave us a set of positive or negative number

##############################################################
2-print_alphabet.c

this code provide us with the length of characters from a to z
##############################################################




3-print_alphabets.c

this code provide us with the length of characters from a to z
in lowercase and uppercase
###############################################################



##############################################################


4-print_alphabt.c



this code provide us with the length of characters from a to z
but excluded q && e
###############################################################

##############################################################

5-print_numbers.c



this code provide us with the length numbers from 0 to 9
###############################################################

##############################################################

6-print_numberz.c

this code provide us with the length numbers from 48 to 58  

############################################################





7-print_numberz.c

this code provide us with the length  of letters  from z a  
############################################################

8-print_base16.c

this  program will prints all the numbers of base 16 in lowercase, followed by a new line.

#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char letter;

	/* Print numbers 0-9 */
	for (num = 0; num <= 9; num++)
		putchar(num + '0');

	/* Print lowercase letters a-f */
	for (letter = 'a'; letter <= 'f'; letter++)
		putchar(letter);

	putchar('\n');

	return (0);
}

#################################################################

9-print_comb.c


this program will prints all possible combinations of single-digit numbers.

Numbers will be separated by ,, followed by a space
Numbers will be printed in ascending order


#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');

		if (num != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return 0;
}
