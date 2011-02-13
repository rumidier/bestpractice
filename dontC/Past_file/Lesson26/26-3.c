#include <stdio.h>

void copyarray (int *src, int *dest, int len);
void showarrelem (int *ary, int len);

int
main (int   argc,
      char *argv[])
{
  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[5];

  copyarray (arr1, arr2, 5);
  showarrelem (arr2, 5);

  return 0;
}

void copyarray (int *src,
                 int *dest,
                 int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      src[i] = dest[i];
    }
}

void showarrelem (int *ary,
                  int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      printf ("%d", ary[i]);
      len = i;
    }
  printf ("\n");
}
