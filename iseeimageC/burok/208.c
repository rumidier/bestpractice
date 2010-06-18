#include <stdio.h>
#include <stdlib.h>

int
compare (const void *a, const void *b)
{
  int x = * ((int *) a);
  int y = * ((int *) b);

  if (x > y)
    return 1;
  else if (x < y)
    return -1;
  else
    return 0;
}

int
main (int argc, char *argv[])
{
  int nums[] = {5, 8, 3, 7, 4, 2, 9, 1, 6, 10};
  int a = 7, i;
  int *p;

  qsort (nums, 10, sizeof (int), compare);

  for (i = 0; i < 10; i++)
    printf ("%d ", nums [i]);

  printf ("\n%d을 검색합니다. \n", a);
  p = (int *) bsearch (&a, nums, 10, sizeof (int), compare);

  if (p == NULL)
    printf ("%d 이 발견되지 않았습니다.\n", a);
  else
    printf ("%d은 배열 nums[%d]에 있습니다.\n", a, p - nums);

  return 0;
}
