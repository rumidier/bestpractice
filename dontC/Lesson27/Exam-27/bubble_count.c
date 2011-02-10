#include <stdio.h>
#include <stdlib.h>

int acd_sort (int num1, int num2);
int quick_sort (const void *, const void *);
void bubblesort (int *ary, int len, int (*sortfunc) (int, int));

int acd_count;
int quick_count;

int
main (int   argc,
      char *argv[])
{
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int i;

  acd_count = 0;
  quick_count = 0;

  bubblesort (arr, sizeof (arr) / sizeof (int), acd_sort);
  for (i = 0; i < 9; i++)
    printf ("%d ", arr[i]);
  printf ("acdcount[%d]\n", acd_count);
  printf ("\n");

  qsort ((void *)arr1, sizeof (arr1) / sizeof (int), sizeof (int), quick_sort);
  for (i = 0; i < 9; i++)
    printf ("%4d", arr1[i]);
  printf ("quick_count[%d]\n", quick_count);
  printf ("\n");

  return 0;
}

int
acd_sort (int n1, int n2)
{
  acd_count++;

  if (n1 > n2)
    return 1;
  else
    return 0;
}

void
bubblesort (int *ary, int len, int (*sortfunc) (int, int))
{
  int i, j;
  int temp;

  for (i = 0; i < len - 1; i++)
    {
      for (j = 0; j < (len - i) - 1 ;j++)
        {
          if (sortfunc (ary[j], ary[j + 1]))
            {
              temp = ary[j];
              ary[j] = ary [j + 1];
              ary[j + 1] = temp;
            }
        }
    }
}

int
quick_sort (const void *p1, const void *p2)
{
  int n1 = *((int *) p1);
  int n2 = *((int *) p2);
  int ret;

  quick_count++;

  if (n1 > n2)
    ret = 1;
  else if (n1 < n2)
    ret = -1;
  else
    ret = 0;

  return ret;
}
