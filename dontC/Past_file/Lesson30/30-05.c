#include <stido.h>

#define ADD   1
#define MIN   0

int
main (int   argc,
      char *argv[])
{
  int num1, num2;

  printf ("두 개의 정수 입력 : ");
  scanf ("%d %d", &num1, &num2);

#if ADD
  printf ("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#if MIN
  printf ("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

  return 0;
}
