#include <stdio.h>

static void
copy_cat_array (int *src, int *dst, int len);

int
main (int   argc,
      char *argv[])
{
  int len;
  int count;
  int i;
  int src[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int dst[3][4];

  count = 0;
  len = 12;

  copy_cat_array (src[0], dst[0], len);

  printf ("원본 데이터 출력\n");

  for (i = 0; i < 12; i++)
    {
      count++;
      printf ("%4d", *(*(src) + i));

      if ( count == 4)
        {
          count = 0;
          printf ("\n");
        }
    }

  printf ("\n");
  printf ("\n");
  printf ("복사본 데이터 출력\n");

  for (i = 0; i < 12; i++)
    {
      count++;
      printf ("%4d", *(*(dst) + i));

      if ( count == 4)
        {
          count = 0;
          printf ("\n");
        }
    }

  return 0;
}

static void
copy_cat_array (int *src, int *dst, int len)
{
  int i;

  for (i = 0; i < len; i++)
    {
      *(dst + i) = *(src + i);
    }
}
