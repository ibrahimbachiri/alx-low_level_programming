#ifndef DOG_H
#define DOG_H

/* Define the struct dog type */
struct dog {
    char *name;
    float age;
    char *owner;
};

/* Define the new type dog_t */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(dog_t *d, char *name, float age, char *owner);
void print_dog(dog_t *d);

#endif /* DOG_H */
