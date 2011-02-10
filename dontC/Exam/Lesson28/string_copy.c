#include <stdio.h>

#define SRC_MAX     10

static void
print_array (int *num,
             int  len);

static void
copyarray (int *src,
           int *dest,
           int  len);

int
main (int   argc,
      char *argv[])
{
  int len;
  int src[SRC_MAX] = { 2, 65, 45, 75, 33, 65, 667, 334, 234, 4 };
  int dst[SRC_MAX];

  len = sizeof (src) / sizeof (int);
  print_array (src, len);

  copyarray (src, dst, len);

  len = sizeof (dst) / sizeof (int);
  print_array (dst, len);

  return 0;
}

static void
print_array (int *num,
             int  len)
{
  int i;

  for (i = 0; i < len; i++)
    {
      printf ("%d ", num[i]);
    }
  printf ("\n");
}

static void
copyarray (int *src1,
           int *dest1,
           int  len)
{
  int j;

  for (j = 0; j < len; j++)
    {
      *dest1++ = *src1++ ;
    }
}
