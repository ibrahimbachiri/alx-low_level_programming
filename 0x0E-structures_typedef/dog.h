#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A simple structure for a dog's information.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/* Function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
