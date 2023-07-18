#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog.
 * @name: Pointer to the dog's name.
 * @age: The age of the dog.
 * @owner: Pointer to the owner's name.
 *
 * Description: Structure representing a dog with name, age, and owner.
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Define a new type dog_t as a new name for struct dog */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
/* Initializes a struct dog with the given values for name, age, and owner. */

void print_dog(struct dog *d);
/* Prints the details of a struct dog. If an element of d is NULL, print (nil)
 * instead of this element. */

dog_t *new_dog(char *name, float age, char *owner);
/* Creates a new dog and returns a pointer to it. */

void free_dog(dog_t *d);
/* Frees the memory allocated for a struct dog. */

#endif /* DOG_H */
