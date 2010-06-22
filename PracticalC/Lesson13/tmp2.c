/****
 * tmp_name -- 임시 파일명 변환
 *
 * 함수가 호출될 때마다,
 * 새로운 파일명이 반환된다.
 *
 * 경고: 주의할 사항이 있지만 노력해서 알아본 후
 *      해답을 참조하기로 하자.
 *
 * 반환값
 *      새로운 파일명애 대한 포인터
*****/

#include <stdio.h>
#include <string.h>

char
*tmp_name (void)
{
  static char name [30];    /* 만들 파일명 */
  static int sequence = 0;    /* 가장 최근의 순차번호 */

  ++sequence;   /* 다음 파일명으로 이동 */

  strcpy (name, "tmp");

  /* 순차번호 붙임 */
  name [3] = sequence + '0';

  /* 문자열 끝 */
  name [4] = '\0';

  return name;
}

int
main (int argc, char *argv[])
{
  char *tmp_name (void);

  char *name1;
  char name_1 [100];
  char *name2;

  name1 = tmp_name ();
  strcpy (name_1, name1);
  name2 = tmp_name ();

  printf ("Name1: %s\n", name_1);
  printf ("Name2: %s\n", name2);

  return 0;
}
