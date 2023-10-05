#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add/update the key/value pair.
 * @key: The key (cannot be an empty string).
 * @value: The value associated with the key (can be an empty string).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
  unsigned long int index;
  hash_node_t *new_node = NULL, *current = NULL;

  if (ht == NULL || key == NULL || strlen(key) == 0)
    return (0);

  index = key_index((const unsigned char *)key, ht->size);

  current = ht->array[index];

  /* Check for collisions */
  while (current != NULL)
    {
      if (strcmp(current->key, key) == 0)
	{
	  /* Update the value if the key already exists */
	  free(current->value);
	  current->value = strdup(value);
	  if (current->value == NULL)
	    return (0);
	  return (1);
	}
      current = current->next;
    }

  /* Create a new node */
  new_node = malloc(sizeof(hash_node_t));
  if (new_node == NULL)
    return (0);

  new_node->key = strdup(key);
  if (new_node->key == NULL)
    {
      free(new_node);
      return (0);
    }

  new_node->value = strdup(value);
  if (new_node->value == NULL)
    {
      free(new_node->key);
      free(new_node);
      return (0);
    }

  /* Insert new node at the beginning of the list */
  new_node->next = ht->array[index];
  ht->array[index] = new_node;

  return (1);
}
