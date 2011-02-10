#include <stdio.h>

void copyarray (int *src, int *dest, int len, int l_len);

int
main (int   argc,
      char *argv[])
{

  int i, j;
  int src[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int dest[3][4];

  for (i = 0; i < 3; i++)
    {
       for (j = 0; j < 4; j++)
         {
           printf ("%3d ", src[i][j]);
         }
       printf ("\n");
    }

  copyarray (src, dest, 3, 4);

  for (i = 0; i < 3; i++)
    {
       for (j = 0; j < 4; j++)
         {
           printf ("%3d ", dest[i][j]);
         }
       printf ("\n");
    }
  

  return 0;
}

void
copyarray (int *src,
           int *dest,
           int l_len,
           int r_len)
{
  int i, j;

  for (i = 0; i < l_len; i++)
    {
      for (j = 0; j < r_len; j++)
        {
          *(*(dest + i) + j) = *(*(src + i) + j);
        }
    }
}
