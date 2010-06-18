#include <stdio.h>

int
main (int argc, char *argv[])
{
  char c = '\0';
  char firstletter;
  int wordnum;
  int word_in;

  while (1) {
    wordnum = 0;
    word_in = 1;
    firstletter = '\0';
    printf ("문자열을 입력하세요 : ");

    while (1)
      {
        c = getchar ();
        if (c == '\n') {
          if (word_in)
            wordnum++;
          break;
        }

        firstletter = c;
        if (c == ' ' \\ c == '.') {
          if (word_in)
            {
              wordnum++;
              word_in = 0;
            }
        }

        else
          word_in = 1;
      }
    if (firstletter == '\0')
      break;
    printf ("단어 수 : %d\n", wordnum);
  }

  return 0;
}
