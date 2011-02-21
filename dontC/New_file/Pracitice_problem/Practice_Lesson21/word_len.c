#include <stdio.h>
#include <string.h>

static int
word_len_value (char *str);

int
main (int   argc,
      char *argv[])
{
  char word_buf[100];
  printf ("단어 입력 : ");
  scanf ("%s", word_buf);
  printf ("입력된 단어의 길이 : %d \n", word_len_value (word_buf));

  return 0;
}

static int
word_len_value (char *str)
{
  int i;
  i = 0;

  while (1)
    {
      if (str[i] == '\0')
        break;
      i++;
    }

  return i;
}
