/*****
 * Database -- 저장된 목록에서 이름을 찾는
 *              간단한 데이터베이스 프로그램
 * 사용법:
 *      database
 *      사용자에게 이름을 입력할 것을 요구한다.
 *      이름 입력; 그러면 프로그램은
 *      그 이름이 목록에 있는지 알려준다.
 *
 *      이름을 입력하지 않으면 프로그램을 종료한다.
*****/

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 80

int
main (int argc, char *argv[])
{
  char name [STRING_LENGTH];

  int lookup (char const *const name);

  while (1) {
    printf ("Enter name: ");
    fgets (name, sizeof (name), stdin);

    /* 이름을 입력했는지 확인 */
    /* (개행문자도 1문자임을 기억한다.) */
    if (strlen (name) <= 1)
      break;

    name [strlen (name) - 1] = '\0';

    if (lookup (name))
      printf ("%s is in the list\n", name);
    else
      printf ("%s is not in the list\n", name);
  }

  return 0;
}

/*****
 * lookup -- 목록에서 이름 찾기
 *
 * 매개변수
 *      name -- 찾을 이름
 *
 * 반환값
 *    1 -- 목록에 이름이 있으면
 *    0 -- 없으면`
*****/

int
lookup (char const *const name)
{
  /* 데이터베이스로 사람들의 이름 넣기 */
  /* 주의 : 목록의 마지막 표시로 널(NULL) 을 사용 */

  static char *list [] = {
    "John",
    "Jim",
    "Jane",
    "Clyde",
    NULL
  };

  int index;

  for (index = 0; list [index] != NULL; ++index) {
    if (strcmp (list [index], name) == 0)
      return 1;
  }

  return 0;
}
