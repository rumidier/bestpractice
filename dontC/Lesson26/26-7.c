#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int idx = 0;
  /* argc에 저장된 값 조회 */

  /* argv가 참조하는 문자열들 출력 */

  while (argv[idx] != NULL)
    {
      printf ("argv[%d] : %s \n", idx, argv[idx]);
      idx++;
    }

  return 0;
}
