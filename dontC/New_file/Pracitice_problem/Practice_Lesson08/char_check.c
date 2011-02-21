/*********************************************************************************************************
 * 5장에서 자료형을 설명하면서 int 는 signed int와 동일하고, short는 signed short와 동일함을 설명하였다.
 * 하지만 char형은 예외이다. 컴파일러에 따라서 char 를 signed char로 처리하는 컴파일러도 있고, unsigned char
 * 로 처리하는 컴파일러도 있다. 여러분의 개발환경에서는 char가 어떻게 처리되는지 궁금하지 않은가? 이를 확인
 * 하기위한 예제를 작성해 보자.
 **********************************************************************************************************/
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char num1 = -1;
  signed char num2 = -1;
  unsigned char num3 = -1;

  printf ("char num1 %d \n", num1);
  printf ("signed char num2 %d \n", num2);
  printf ("unsigned char num3 %d \n", num3);

  return 0;
}
