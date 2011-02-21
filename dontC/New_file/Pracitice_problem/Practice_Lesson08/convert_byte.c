/************************************************************************************************************
 * 12기가 바이트가 몇 메가 바이트인지, 그리고 몇 킬로 바이트인지 계산하여 출력하는 프로그램을 작성하자.
 * 단 기가 바이트를 메가바이트로, 기가 바이트를 킬로 바이트로 변환하는 함수를 각각 다음의 형태로 정의
 * 해야한다.
    static int
    convert_byte_giga_to_mega (int num);

    static int
    convert_byte_giga_to_kilo (int num);
 * 그리고 이 두 함수 내에서는 절대로 곱셈 연산을 하면 안되고, 대신 다음 함수를 활용해야 한다.
 *
   static int
   convert_byte_multi1024 (int num)
    {
      return num * 1024;
    }
 ************************************************************************************************************/
#include <stdio.h>

static int
convert_byte_multi1024 (int num);

static int
convert_byte_giga_to_mega (int num);

static int
convert_byte_giga_to_kilo (int num);

static int
convert_byte_multi1024 (int num)
{
  return num * 1024;
}

static int
convert_byte_giga_to_mega (int num)
{
  return  convert_byte_multi1024 (num);
}

static int
convert_byte_giga_to_kilo (int num)
{
  int num2;
  num2 = convert_byte_multi1024 (num);

  return convert_byte_multi1024 (num2);
}

int
main (int   argc,
      char *argv[])
{
  int giga;
  int kilo;
  int mega;

  giga = 12;
  mega = convert_byte_giga_to_mega (giga);
  printf ("%dgiga byte는 %dmega byte 입니다\n", giga, mega);

  kilo = convert_byte_giga_to_kilo (giga);
  printf ("%dgiga byte는 %dkilo byte 입니다\n", giga, kilo);
  
  return 0;
}
