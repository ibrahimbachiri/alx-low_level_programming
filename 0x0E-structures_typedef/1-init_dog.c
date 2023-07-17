#include "dog.h"
#include <stddef.h>
/**
 * init_dog - Initializes a struct dog variable.
 * @d: Pointer to the struct dog variable to be initialized.
 * @name: Pointer to the string representing the dog's name.
 * @age: The age of the dog.
 * @owner: Pointer to the string representing the owner's name.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d != NULL)
    {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}
