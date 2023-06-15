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


this will print with proper grammar, but the outcome is a piece of art
in a new line to standard output as well using printf instead of puts
5-printf.c


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




