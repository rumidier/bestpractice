/**
 * 회문(palindrome) 판단
 *
 *   난 정말 C Programming을 공부한 적이 없다구요!
 *   p.502, 문제 4
 */

#include <stdio.h>
#include <string.h>

int
main (int   argc,
      char *argv[])
{
  char line [255];
  int count, i, check;

  printf ("단어 입력: ");
  scanf ("%s", line);

  count = strlen (line);

  for (i = 0; i < count; i++)
    {
      if (line[i] == line[count -(i + 1)] ||
          line[i] - 32 == line[count - (i + 1)] ||
          line[i] == line[count - (i + 1)] - 32)
        {
          check = 1;
        }
      else
        {
          check = 0;
        }
    }

  if (check == 1)
    {
      printf ("입력하신 단어는 회문입니다.\n");
    }
  else
    {
      printf ("입력하신 단어는 회문이 아닙니다.\n");
    }



  return 0;
}
