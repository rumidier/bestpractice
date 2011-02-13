/**
 * P613
 * 최대 길이가 20을 넘지 않는 3개의 문자열을 저장할 수 있는 2차원 배열을
 * 힙에 할당하고, 프로그램 사용자로부터 3개의 문자열을 이 배열에 입력
 * 받아서 , 입력된 순서대로 출력을 하는 프로그램을 작성하자.
 */

#include <stdio.h>
#include <stdlib.h>

typedef char (*STR_ARR)[20];

int
main (int   argc,
      char *argv[])
{
  STR_ARR strary = (STR_ARR) malloc (sizeof (char) * 20 * 3);

  int i;

  for (i = 0; i < 3; i++)
    {
      printf ("문자열 입력 : ");
      scanf ("%s", strary[i]);
    }

  for (i = 0; i < 3; i++)
    printf ("문자열 %d : %s \n", i + 1, strary[i]);

  free (strary);
  return 0;
}
