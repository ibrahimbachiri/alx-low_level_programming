##alx-low_level_programming

0-preprocessor

this script will Export the variable stored in Cfile to c

#!/bin/bash
gcc -E $CFILE > c

#####################################


1-compiler

this script will output the value of c as main.c

#!/bin/bash
gcc -c $CFILE 

######################################


#####################################


2-assembler

#!/bin/bash
gcc -S $CFILE

this script will output main.S

######################################



#####################################

#!/bin/bash

3-name
gcc $CFILE -o cisfun
this script will output cisfun 

######################################




#####################################

4-puts.c

this will print Programming is like building a multilingual puzzle
to, do standard output 

#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 */
int main(void)
{
	puts("\"Programming is like building a multilingual puzzle");

	return (0);
}

######################################



######################################


5-printf.c

this will print with proper grammar, but the outcome is a piece of art
in a new line to standard output as well using printf instead of puts


#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program prints a statement with proper grammar,
 * representing art.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("with proper grammar, but the outcome is a piece of art,\n");

	return (0);
}

###########################################################


6-size.c

this code will print out the size of the following data type:


#include <stdio.h>


/**
 * main - Entry point of the program
 * 
 * Description: Prints the sise of various types on the computer
 * it is compiled and run on.
 *
 * Return: Always 0 (Success)
 */
 int main(void)
 {
   printf("Size of a char: %lu byte(s)\n", sizeof(char));
   printf("Size of an int: %lu byte(s)\n", sizeof(int));
   printf("Size of a long int: %lu byte(s)\n", sizeof(long int));
   printf("Size of a long long int: %lu byte(s)\n", sizeof(long long int));
   printf("Size of a float: %lu byte(s)\n", sizeof(float));

   return (0);

 }
 



