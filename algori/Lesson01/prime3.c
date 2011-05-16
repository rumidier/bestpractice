#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 9999

int
main (int   argc,
      char *argv[])
{
  int *iptr;
  int i, j;

  iptr = (int *) calloc (MAX, sizeof (int));

  if (iptr == NULL)
    {
      puts ("n Memory allocation error ! ");
      exit (1);
    }

  for (i = 2; i < MAX; i++)
    {
      if (iptr[i] == 1)
        continue;

      j = i;

      while ((j += i) <= MAX) //j의 배수 값을 지운다
        iptr[j] = 1;
    }

  for (i = 2; i <= MAX; i++)
    if (iptr[i] == 0)
      printf ("\t%6d", i);

  return 0;
}
