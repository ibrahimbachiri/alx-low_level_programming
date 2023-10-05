#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - A function that creates a hash table.
 * @size: The size of hash table.
 * Return: A pointer to the new hash table in memory (heap).
 */
shash_table_t *shash_table_create(unsigned long int size)
{
  unsigned long int i = 0;
  shash_table_t *new_table = NULL;

  new_table = malloc(sizeof(shash_table_t));
  if (!new_table)
    return (NULL);
  new_table->size = size;
  new_table->array = malloc(sizeof(shash_node_t *) * size);
  if (!new_table->array)
    {
      free(new_table);
      return (NULL);
    }
  for (; i < size; i++)
    (new_table->array)[i] = NULL;
  return (new_table);
}

/**
 * shash_table_set - A function that sets a key value pair in the hash table.
 * @ht: A pointer to hash table to set in.
 * @key: The key to set in hash table.
 * @value: The value to set as hash_node's value.
 * Return: 1 on success, or 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
  unsigned long int index = 0;
  char *value_dup = NULL, *key_dup = NULL;
  shash_node_t *new_node = NULL, *tmp_node = NULL;

  if (!ht || !key || !value)
    return (0);
  else if (strlen(key) == 0)
    return (0);
  value_dup = strdup(value);
  key_dup = strdup(key);
  new_node = malloc(sizeof(shash_node_t));
  if (!new_node)
    return (0);
