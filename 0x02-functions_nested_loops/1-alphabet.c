#include <stdio.h>
#include "main.h"


int _putchar(int c)
{
  return putchar(c);
}

void print_alphabet(void)
{
  int a;

  for (a = 'a'; a <= 'z'; a++)
  {
    _putchar(a);
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
