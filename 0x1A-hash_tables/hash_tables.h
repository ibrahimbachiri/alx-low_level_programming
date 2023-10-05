#ifndef HASH_TABLES_H
#define HASH_TABLES_H

/* Include system headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, a string
 * @value: The associated value, a string
 * @next: A pointer to the next node in the linked list (for collision handling)
 */
typedef struct hash_node_s
{
  char *key;
  char *value;
  struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of hash_node_t pointers (buckets)
 */
typedef struct hash_table_s
{
  unsigned long int size;
  hash_node_t **array;
} hash_table_t;

/* Function prototypes */

/**
 * hash_table_create - Creates a new hash table
 *
 * @size: The size of the hash table (number of buckets)
 * Return: A pointer to the newly created hash table or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size);

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 *
 * @str: The input string to hash
 * Return: The computed hash value
 */
unsigned long int hash_djb2(const unsigned char *str);

/**
 * key_index - Computes the index of a key in a hash table
 *
 * @key: The key string to compute the index for
 * @size: The size of the hash table (number of buckets)
 * Return: The computed index value
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/**
 * hash_table_set - Adds an element to a hash table
 *
 * @ht: The hash table to add the element to
 * @key: The key string (must not be an empty string)
 * @value: The value string to associate with the key (can be an empty string)
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table
 *
 * @ht: The hash table to search
 * @key: The key to search for
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key);

/**
 * hash_table_print - Prints the elements of a hash table
 *
 * @ht: The hash table to print
 */
void hash_table_print(const hash_table_t *ht);

/**
 * hash_table_delete - Deletes a hash table and its elements
 *
 * @ht: The hash table to delete
 */
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLES_H */
