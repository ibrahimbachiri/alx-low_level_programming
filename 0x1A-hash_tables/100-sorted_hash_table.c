#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the element in
 * @key: The key string (must not be an empty string)
 * @value: The value string to associate with the key (can be an empty string)
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *tmp;
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			if (tmp->value == NULL)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}
	new_node = malloc(sizeof(shash_node_t));
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
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	/* Insert into sorted linked list */
	if (ht->shead == NULL || strcmp(new_node->key, ht->shead->key) <= 0)
	{
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		if (ht->shead != NULL;
				ht->shead->sprev = new_node;
				ht->shead = new_node;
				}
				else
				{
				tmp = ht->shead;
				while (tmp->snext != NULL && strcmp(tmp->snext->key, new_node->key) <= 0;
						tmp = tmp->snext;
						new_node->snext = tmp->snext;
						new_node->sprev = tmp;
						if (tmp->snext != NULL)
						tmp->snext->sprev = new_node;
						tmp->snext = new_node;
						}
						if (ht->stail == NULL)
						ht->stail = new_node;
						return (1);
						}
/**
 * shash_table_get - Retrieves the value associated with a key in the sorted hash table
 * @ht: The sorted hash table to search
 * @key: The key to search for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints the elements of the sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;
	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the elements of the sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int first = 1;
	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		if (first)
			first = 0;
		else
			printf(", ");
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and its elements
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *next;
	unsigned long int i;
	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = next;
		}
	}
	free(ht->array);
	free(ht);
}
