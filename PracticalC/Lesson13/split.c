/********************
 * my_strchr -- 문자열 안의 문자 찾기
 *        표준 라이브러리 함수와 중복됨
 *        보여주기 위한 목적으로 작성됨
 *
 * 매개변수
 *        string_ptr -- 살펴볼 문자열
 *        find -- 찾을 문자
 * 반환값
 *        문자열 안 해당 문자의 첫번째 위치 포인터
 *        또는 에러 발생시 NULL
********************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char
*my_strchar (char * string_ptr, char find)
{
  while (*string_ptr != find) {
    if (*string_ptr == '\0')
      return NULL;

    ++string_ptr;
  }
  return string_ptr;
}

int
main (int argc, char *argv[])
{
  char line [80];
  char *first_ptr;
  char *last_ptr;

  fgets (line, sizeof (line), stdin);

  line [strlen (line) - 1] = '\0';

  last_ptr = line;

  first_ptr = my_strchr (line, '/');

  if (first_ptr == NULL) {
    fprintf (stderr,
             "Error: Unable to find slash in %s\n", line);
    exit (8);
  }

  *first_ptr = '\0';

  ++first_ptr;

  printf ("First:%s Last:%s\n", first_ptr, last_ptr);

  return 0;
}
