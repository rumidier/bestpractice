#include <stdio.h>

char * StringTokenize(char * str, char * delim)
{
  static char * nextTokenPos;
  char * curTokenPos;
  char * curStrPos;   

  if(str!=NULL)
    {
      curTokenPos=str;
      curStrPos=str;
      nextTokenPos=(char*)-1;  
    }
  else
    {
      curTokenPos=nextTokenPos;
      curStrPos=nextTokenPos;
    }

  if(nextTokenPos==NULL)  //문자열의 끝 도달을 검사.
    return NULL;

  while(1)
    {
      if(*curStrPos==0)   // 문자열의 끝을 검사.
        {
          nextTokenPos=NULL;
          break;
        }

      if(*curStrPos == delim[0])  // 토큰 구분 문자 발견.
        {
          *curStrPos=0;
          nextTokenPos=curStrPos+1;
          break;
        }

      curStrPos++;
    }

  return curTokenPos;
}

int main(void)
{
  char str[]="111-2222-3333";

  char * delim="-";
  char * token;

  token=StringTokenize(str, delim);
  printf ("[%c]\n", *(token + 3));

  while(token!=NULL)
    {
      puts(token);
      token=StringTokenize(NULL, delim);
    }

  return 0;
}
