/********
 * copy_string -- 문자열을 복사하는 함수
 *
 * 매개변수
 *      dest -- 문자열을 복사할 위치
 *      source -- 문자열을 얻어올 위치
********/

#include <stdio.h>

void
copy_string (char *dest, char *source)
{
  while (1) {
    *dest = *source;

    if (*dest == '\0')
      return;
    ++dest;
    ++source;
  }
}

