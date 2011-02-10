#include <stdio.h>
#include <string.h>
#include <malloc.h>

static char * 
substring (char *string,
           int i, int j)
{
  char *temp;
  int k;
  temp = (char *) malloc (sizeof (char) * (j - i + 1));

  k = strlen(string) - 1;

  if (j <= k)
    {
      strncpy(temp , string + i, j - i + 1 );
    }
  else
    {
      printf(" 오류 , 범위 초과 ! [%d / %d]",j , k);
    }

  return temp;
}

int 
main(int   argc,
     char *argv[])
{
  char *str = "I love you";
  char *str2 = NULL;

  // strncpy(str2 , str+2,5);
  str2 = substring(str,2,5);
  puts(str2);

  return 0;
}
