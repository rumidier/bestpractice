#include <stdio.h>

typedef struct box
{
  int data;
  struct box * boxref;
} box;

int
main (int   argc,
      char *argv[])
{
  int i;
  box * bxptr;

  box b1 = {1, NULL};
  box b2 = {11, NULL};

  b1.boxref = &b2;
  b2.boxref = &b1;

  bxptr = &b1;

  for ( i = 1; i <= 10; i++)
    {
      printf ("%3d", bxptr -> data);
      (bxptr -> data)++;
      bxptr = bxptr -> boxref;
      if (!(i % 2))
        printf ("\t");
    }

  return 0;
}
