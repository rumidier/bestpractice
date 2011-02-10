#include <stdio.h>
#include <string.h>

int sort (int num, int num2);
void bubblesort (int *ary, int len, int (*sortfunc) (int, int));

int
main (int argc,
      char *argv[])
{
  int arr[] = {3, 2, 1, 4, 6, 8, 7, 5, 3, 4, 5};
  int i;

  bubblesort (arr, sizeof (arr) / sizeof (int), sort);

  for (i = 0; i < sizeof (arr) / sizeof (int); i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");

  return 0;
}

int
sort (int num1,
      int num2)
{
  if ((num1 % 2) == 0 && (num2 % 2) != 0)
    return 1;
  if ((num1 % 2) != 0 && (num2 % 2) == 0)
    return 0;

  if (num1 > num2)
    return 1;
  else
    return 0;
}

void
bubblesort (int *ary,
            int  len,
            int (*sortfunc) (int, int))
{
  int i, j;
  int temp;

  for (i = 0;  i < len - 1; i++)
    {
      for (j = 0; j < (len - i); j++)
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
