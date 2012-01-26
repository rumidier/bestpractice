#include <stdio.h>

int
LSearch (int ar[],
         int len,
         int target)
{
  int i;

  for (i = 0; i < len; i++)
    {
      if (ar[i] == target)
        return i;
    }

  return -1;
}

int
main (int   argc,
      char *argv[])
{
  int arr[] = {3, 5, 2, 4, 9};
  int idx;

  idx = LSearch (arr, sizeof(arr) / sizeof(int), 4);
  if (idx == -1) {
    printf ("탐색 실패 \n");
  }
  else {
    printf ("타켓 저장 인덱스: %d \n", idx);
  }

  idx = LSearch(arr, sizeof (arr)/sizeof(int), 7);
  if (idx == -1) {
    printf ("탐색 실패 \n");
  }
  else {
    printf ("타켓 저장 인덱스: %d \n", idx);
  }

  return 0;
}
