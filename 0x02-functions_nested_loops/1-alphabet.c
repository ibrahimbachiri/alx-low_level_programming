#include <stdio.h>
#include "main.h"

void Alpha(void)
{
  int a;

  for (a = 'a'; a <= 'z'; a++)
  {
    _putchar(a);
  }

  _putchar('\n');
}

int _putchar(int c)
{
  return putchar(c);
}

int main(void)
{
  Alpha();
  return 0;
}
