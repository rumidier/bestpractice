#include <stdio.h>

void
initarrwd3 (int  (*ar)[3],
             int  height,
             int  initnum)
{
  int i, j;

  for (i = 0; i < height; i++)
    {
      for (j = 0; j < 3; j++)
        {
          ar[i][j] = initnum;
        }
    }
}

void initarrwd4 (int  (*ar)[4],
                 int  height,
                 int initnum)
{
  int i, j;
  for (i = 0; i < height; i++)
    for (j = 0; j < 4; j++)
      ar[i][j] = initnum;
}

int
main (int   argc,
      char *argv[])
{
  int i, j;
  int arr1[3][3];
  int arr2[4][4];

  int (*parr1)[3] = arr1;
  int (*parr2)[4] = arr2;

  initarrwd3 (arr1, 3, 5);
  initarrwd4 (arr2, 4, 7);

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
        {
          printf ("%4d", parr1[i][j]);
        }
      printf ("\n");
    }
  printf ("\n");

  for (i = 0; i < 4; i++)
    {
      for (j = 0; j < 4; j++)
        {
          printf ("%4d", parr2[i][j]);
        }
      printf ("\n");
    }

  return 0;
}
