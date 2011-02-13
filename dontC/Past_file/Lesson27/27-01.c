#include <stdio.h>

void funcone (void)
{
  printf ("Funcone 함수가 호출 되었다! \n");
}

void functwo (void)
{
  printf ("Functwo 함수가 호출 되었다! \n");
}

int
main (int   argc,
      char *argv[])
{
  funcone ();
  functwo ();

//printf ("Funcone의 주소 값 : %#x \n", funcone);
  printf ("Funcone의 주소 값 : %x \n", funcone);
//printf ("Functwo의 주소 값 : %#x \n", functwo);
  printf ("Functwo의 주소 값 : %x \n", functwo);

  return 0;
}
