/*
 * facttail.c
 */

#include "facttail.h"

/*
 * facttail
 */

int
facttail (int n, int a)
{
  /*
   * 꼬리 재귀 방법으로 계승을 계산
   */

  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else
    return facttail (n - 1, n * a);
}
