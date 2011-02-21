#include<stdio.h>
#include <string.h>


int main(void)
{
  char word[100];
  char word_len;
  int value = 0;
  int b=0, i;

  printf("단어를 입력하시오 : ");
  scanf("%s",word);
  word_len = strlen (word);

  if (word_len == 0)
    return 1;

  b = word_len - 1;
  for(i = 0; i < word_len / 2 ; i++)
    {

      if(word[i] == word[b])
        {
          b--;
          value = 1;
        }
      else
        {
          value = 0;
          break;
        }
    }

  if (value == 0)
    {
      printf ("회문이 아닙니다.\n");
    }
  else if (value == 1)
    {
      printf ("회문 입니다.\n");
    }
  else
    {
      printf ("알지 못하는 오류가 있습니다\n");
    }

return 0;
}
