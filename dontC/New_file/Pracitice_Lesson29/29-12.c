#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str[] = "한글도 얼마든지 전달인자가 될 수 있습니다.";
  char *str_ptr;

  str_ptr = strstr (str, "가 될 수 있습");
  printf ("시작 위치 이후 문자열 : %s \n", str_ptr);

  return 0;
}
