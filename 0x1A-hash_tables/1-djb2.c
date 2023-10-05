/**
 * hash_djb2 - Hash function using the DJB2 algorithm
 * @str: The string to hash
 *
 * Return: The hash value generated from the input string
 */
unsigned long int hash_djb2(const unsigned char *str)
{
  unsigned long int hash;
  int c;

  hash = 5381; /* Initialize hash to a constant value */
  while ((c = *str++)) /* Loop through each character in the string */
    {
      hash = ((hash << 5) + hash) + c; /* Update the hash value */
    }
  return (hash);
}
