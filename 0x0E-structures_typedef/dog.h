#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog.
 * @name: Pointer to the dog's name.
 * @age: The age of the dog.
 * @owner: Pointer to the owner's name.
 *
 * Description: This structure represents a dog with its name,
 * age, and owner's name.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
