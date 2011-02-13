#include <stdio.h>
void copyarray (const int *const src,
                int *const dest,
                const int len);
void showarrelem (const int *const ary, const int len);

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

void copyarray (const int *const src,
                int *const dest,
                const int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
     dest[i] = src[i]; //컴파일 오류
    }
}

void
showarrelem (const int *const ary,
                        const int len)
{
  int i;

  for (i = 0; i < len; i++)
    {
      printf ("%d", ary[i]);
    }
  printf ("\n");
}
