#include "main.h"
#include <stdio.h>

void print_alphabet(void)
{
  char c;

  for (c = 'a'; c <= 'z'; c++)
  {
    _putchar(c);
  }

  _putchar('\n');
}
/*
int _putchar(int c)
{
  return putchar(c);
  }*/

/*int main()
{
  print_alphabet();
  return (0);
  }*/
