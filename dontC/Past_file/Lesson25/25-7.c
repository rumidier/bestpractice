#include <stdio.h>
#include <stdlib.h>

char *readstring (void);
int *readinteger (void);

int
main (int   argc,
      char *argv[])
{
  char *strptr; // char형 포인터 strptr 선언
  int *numptr; // int형 포인터 numptr 선언

  strptr = readstring ();//line 30
  numptr = readinteger();//line 42

  if (strptr != NULL)
    printf ("읽어 들인 문자열 : %s \n", strptr);//malloc 에서 할당 되었을때 (할당x NULL값)입력값 출력
  if (numptr != NULL)
    printf ("읽어 들인 정수 : %d \n", *numptr);//malloc 에서 할당 되었을때 (할당x NULL값)입력값 출력

  free (strptr);// malloc 함수 해제
  strptr = NULL;
  free (numptr);// malloc 함수 해제
  numptr = NULL;

  return 0;
}

char *readstring (void)
{
  char * sptr = (char *) malloc (sizeof (char) * 20);
  if (sptr == NULL)
    return NULL;

  printf ("문자열 입력 : ");
  scanf ("%s", sptr);

  return sptr;
}

int *readinteger (void)
{
  int *iptr = (int *) malloc (sizeof (int));
  if (iptr == NULL)
    return NULL;

  printf ("정수 입력 : ");
  scanf ("%d", iptr);

  return iptr;
}
