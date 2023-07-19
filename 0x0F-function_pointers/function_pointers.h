#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * struct dog - A simple structure for a dog's information.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 */
void print_name(char *name, void (*f)(char *));
#endif
