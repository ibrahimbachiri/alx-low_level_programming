#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog.
 * @name: Pointer to the string representing the dog's name.
 * @age: The age of the dog.
 * @owner: Pointer to the string representing the owner's name.
 *
 * Return: Pointer to the newly created dog_t structure.
 *         NULL if the function fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    if (name == NULL || owner == NULL)
        return (NULL);
    /* Allocate memory for the dog_t structure */
    new_dog = (dog_t *)malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);
    /* Allocate memory for the name and owner strings */
    new_dog->name = strdup(name);
    if (new_dog->name == NULL)
    {
        free(new_dog);
        return (NULL);
    }
    new_dog->owner = strdup(owner);
    if (new_dog->owner == NULL)
    {
        free(new_dog->name);
        free(new_dog);
        return (NULL);
    }
    /* Assign the age */
    new_dog->age = age;
    return (new_dog);
}
