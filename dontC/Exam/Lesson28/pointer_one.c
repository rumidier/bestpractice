#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = "C Pointer Operation";
  char *ptr = str;

  printf ("%c \n", *(ptr + 10));
  printf ("%c \n", *ptr);
  printf ("%c \n", *(ptr += 10));
  printf ("%c \n", *ptr);

  printf ("%c \n", *(ptr - 8));
  printf ("%c \n", *(ptr));
  printf ("%c \n", *(ptr -= 8));
  printf ("%c \n", *(ptr));

  return 0;
}
