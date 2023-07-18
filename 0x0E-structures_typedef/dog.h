#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog.
 * @name: Pointer to the dog's name.
 * @age: The age of the dog.
 * @owner: Pointer to the owner's name.
 *
 * Description:
 * Structure representing a dog with name, age, and owner.
 */

struct dog
{
    char *name;
    float age;
    char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);

void print_dog(struct dog *d);

dog_t *new_dog(char *name, float age, char *owner);

void free_dog(dog_t *d);

#endif
