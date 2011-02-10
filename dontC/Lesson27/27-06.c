#include <stdio.h>

int acdsort (int n1, int n2);
int dsdsort (int n1, int n2);
void bubblesort (int ary[], int len, int (*sortfunc) (int, int));

int
main (int   argc,
      char *argv[])
{
  int arr[4] = {3, 2, 1, 4};
  int i;

  bubblesort (arr, sizeof (arr) / sizeof (int), acdsort);

  for (i = 0; i < 4; i++)
    printf ("%d ", arr[i]);
  printf ("\n");

  bubblesort (arr, sizeof (arr) / sizeof (int), dsdsort);

  for (i = 0; i < 4; i++)
    printf ("%d ", arr[i]);
  printf ("\n");

  return 0;
}

int
acdsort (int  n1,
         int  n2)
{
  if (n1 > n2)
    return 1;
  else
    return 0;
}

int
dsdsort (int n1,
         int n2)
{
  if (n1 < n2)
    return 1;
  else
    return 0;
}

void
bubblesort (int ary[],
            int len,
            int (*sortfunc) (int, int))
{
  int i, j;
  int temp;

  for (i = 0; i < len - 1; i++)
    {
      for (j = 0; j < (len - i) - 1; j++)
        {
          if (sortfunc (ary[j], ary[j + 1]))
            {
              temp = ary[j];
              ary[j] = ary[j + 1];
              ary[j + 1] = temp;
            }
        }
    }
}
