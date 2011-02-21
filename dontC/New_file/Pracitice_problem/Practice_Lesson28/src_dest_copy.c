#include <stdio.h>
#include <string.h>

static void
copy_array (int *src, int *dest, int len);

int
main (int   argc,
      char *argv[])
{
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int dest[10];
  int len;

  len = 5;
  copy_array (src, dest, len);

  len = 7;
  copy_array (src, dest, len);

  len = 8;
  copy_array (src, dest, len);

  len = 3;
  copy_array (src, dest, len);

  return 0;
}

static void
copy_array (int *src, int *dest, int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      *(dest + i) = *(src + i);
    }
  *(dest + i) = '\0';

  for (i = 0; i < len; i++)
    {
      printf ("%d ",*(dest + i));
    }
  printf ("\n");
}
