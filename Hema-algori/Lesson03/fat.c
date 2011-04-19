/*
 * fact.c
 */

#include "fact.h"

/*
 * fact
 */

int
fact (int n)
{
  /*
   * 재귀적으로 계승을 계산
   */

  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (n == 1)
    return 1;
  else
    return n * fact (n - 1);
}
