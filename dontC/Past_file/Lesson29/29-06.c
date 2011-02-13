/**
 * #include <string.h>
 * size_t strlen (const char *s);
 * 문자열의 길이 정보 반환
 */

#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char str1[] = "1234567";
  char str2[] = "프로그래밍";
  char str3[] = "C Programming";

  printf ("%s : %d \n", str1, strlen (str1));
  printf ("배열 크기 : %d \n", sizeof (str1));

  printf ("%s : %d \n", str2, strlen (str2));
  printf ("배열 크기 : %d \n", sizeof (str2));

  printf ("%s : %d \n", str3, strlen (str3));
  printf ("배열 크기 : %d \n", sizeof (str3));

  return 0;
}
