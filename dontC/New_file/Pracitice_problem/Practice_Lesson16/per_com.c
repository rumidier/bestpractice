#include <stdio.h>

static int
per_return_num (int num);

static int
per_permutation (int n, int n_r);

static int
per_combin (int n, int r, int n_r);

int
main (int   argc,
      char *argv[])
{
  int per;
  int com;
  int samul;
  int n;
  int r;
  int n_r;
  int select_count;

  printf ("사물의 갯수를 정해주세요 : ");
  scanf ("%d", &samul);
  printf ("몇개를 선택 하시겠습니까?");
  scanf ("%d", &select_count);

  n = per_return_num (samul);
  r = per_return_num (select_count);
  n_r = per_return_num (samul - select_count);

  per = per_permutation (n, n_r);
  com = per_combin (n, r, n_r);

  printf ("순열 : %d\n", per);
  printf ("조합 : %d\n", com);

  return 0;
}

static int
per_return_num (int num)
{
  int max_num;
  int i;

  max_num = 1;

  for (i = 1; i <= num; i++)
    {
      max_num *= i;
    }

  return max_num;
}

static int
per_permutation (int n, int n_r)
{
  return (n / (n_r));
}

static int
per_combin (int n, int r, int n_r)
{
  return (n / (r * (n_r)));
}
