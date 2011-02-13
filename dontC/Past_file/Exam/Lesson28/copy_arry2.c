#include <stdio.h>

static void
copyarray (int *src,
           int *dest,
           int  len);

int
main (int   argc,
      char *argv[])
{
  int max_row;
  int max_col;
  int i, j;
  int src[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  int dst[3][4];

  max_row = sizeof (src) / sizeof (src[0]);
  max_col = sizeof (src[0]) / sizeof (int);

  printf ("원본 데이터 출력\n");
  for (i = 0; i < max_row; ++i)
    {
      for (j = 0; j < max_col; ++j)
        {
          printf ("%4d ", src[i][j]);
        }
      printf ("\n");
    }

  for (i = 0; i < max_row; ++i)
    {
      copyarray (src[i], dst[i], max_col);
    }

  max_row = sizeof (dst) / sizeof (dst[0]);
  max_col = sizeof (dst[0]) / sizeof (int);

  printf ("\n");

  printf ("복사본 데이터 출력\n");
  for (i = 0; i < max_row; ++i)
    {
      for (j = 0; j < max_col; ++j)
        {
          printf ("%4d ", dst[i][j]);
        }
      printf ("\n");
    }

  return 0;
}

static void
copyarray (int *src,
           int *dest,
           int  len)
{
  int j;

  for (j = 0; j < len; j++)
    {
      *dest++ = *src++ ;
    }
}
