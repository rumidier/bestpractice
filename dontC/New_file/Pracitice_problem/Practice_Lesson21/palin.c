#include <stdio.h>
#include <string.h>

static int
pal_word_check (char *word);

int
main (int   argc,
      char *argv[])
{
  char word[256];
  int value;
  value = 0;

  printf ("단어 입력 : ");
  scanf ("%s", word);

  value = pal_word_check (word);

  if (value == 1)
    {
      printf ("단어 %s(은)는 회문 입니다.\n", word);
    }
  else
    {
      printf ("단어 %s(은)는 회문이 아닙니다.\n", word);
    }

  return 0;
}

static int
pal_word_check (char *word)
{
  int value;
  int len;
  int mid_len;
  int a, b;

  value = 0;
  len = strlen (word);
  mid_len = len / 2;
  b = len - 1;

  for (a = 0; a < mid_len; a++)
    {
      if (word[a] == word[b] || (word[a] + 32) == word[b] || word[a] == (word[b] + 32))
        {
          value = 1;
          b--;
        }
      else
        {
          value = 0;
          break;
        }
    }

  return value;
}
