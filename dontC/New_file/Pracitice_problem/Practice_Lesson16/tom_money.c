#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int input_mon;
  int output_mon;
  int month;
  int tom_bank;
  int mon_money;

  tom_bank = 50000000;
  input_mon = 1000000;
  output_mon = 2500000;
  month = 0;

  while (1)
    {
      month++;
      mon_money = tom_bank * 0.02;

      tom_bank += mon_money; //이자율
      tom_bank += input_mon; //입금액
      tom_bank -= output_mon; //출금액

      if (tom_bank <= 2500000)
        {
          printf ("잔고 바닥 개월수 : %d\n", month + 1);
          printf ("마지막 출력 금액 : %d\n", tom_bank);
          break;
        }
    }

  return 0;
}
