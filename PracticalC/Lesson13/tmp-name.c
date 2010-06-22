/*****
 * tmp-name - 임시 파일명 변환
 *
 * 이 함수가 호출될 때마다
 * 새로운 이름이 반환된다.
 *
 * 반환값
 *
 *      새 파일명에 대한 포인터
*****/

#include <stdio.h>
#include <string.h>

char
*tmp_name (void)
{
  static char name [30];   /* 만들 파일명 */
  static int sequence = 0;  /* 최근 순차 번호 */

  ++sequence;   /* 다음 파일명으로 이동 */

  strcpy (name, "tmp");

  /* 순차 번호를 붙임 */
  name [3] = sequence + '0';

  /*문자열 끝내기 */
  name [4] = '\0';

  return name;
}

int
main (int argc, char *argv[])
{
  char *tmp_name (void);  /* 임시 파일명 얻기 */

  printf ("Name: %s\n", tmp_name());

  return 0;
}
