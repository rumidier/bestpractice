/*****
 * extended+fgets -- 입력 파일에서 한 줄 읽고
 *                  필요하다면 저장 파일에 저장 한다.
 *
 * 매개변수
        line -- 읽을줄
        size -- sizeof (line) -- 읽을 문자의 최대 개수
        file -- 데이터를 읽어올 파일
                (대개는 stdin)
  반환값
        NULL -- 에러나 파일 끝
        아니면 한 줄 데이터 (fgets과 마찬가지)
*****/
#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 80

char
*extended_fgets (char *, int, FILE *);

int
main (int argc, char *argv[])
{
  char name [STRING_LENGTH];

  int lookup (char const *const name);

  while (1) {
    printf ("Enter: ");
    extended_fgets (name, sizeof (name), stdin);

    if (strlen (name) <= 1)
      break;
    name [strlen (name) -1] = '\0';

    if (lookup (name))
      printf ("%s is in the list\n", name);
    else
      printf ("%s is not in the list\n", name);
  }

  return 0;
}



FILE *save_file = NULL;

char *extended_fgets (char *line, int size, FILE *file)
{
  char *result;

  result = fgets (line, size, file);

  if (save_file != NULL) {
    fputs (line, save_file);
  }

  return result;
}

int
lookup (char const *const name)
{
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
