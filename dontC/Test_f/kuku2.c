#include <stdio.h>

int
main (void)
{
  int dan, result;
  int num = 1;

  for (dan = 2; num < 10; num++)
    {
      result = dan * num;
      printf ("<%d X %d = %d>\n", dan, num, result);
      if (num == 2)
        break;
      /*
       * dan 값은 2 num 값은 1 이므로
       * 2 X 1 = 2 출력후 다음 for문 이동
       * */
      for (dan = 4; num < 10; num++)
        {
          result = dan * num;
          printf ("(%d X %d = %d)\n", dan, num, result);
          if (num == 4)
            break;
          /*
           * dan값은 4 num 은 아직 1 유지
           * 4 X 1 = 4 출력후 다음 for문 이동
           * */
          for (dan = 6; num < 10; num++)
            {
              result = dan * num;
              printf ("{%d X %d = %d}\n", dan, num, result);
              if (num == 6)
                break;
              /*
               * dan 값은 6 num 은 아직 1유지
               * 6 X 1 = 6 출력후 다음 for문 이동
               * */
              for (dan = 8; num < 10; num++)
                {
                  result = dan * num;
                  printf ("[%d X %d = %d]\n", dan, num, result);
                  if (num == 8)
                    break;
                }
            }
        }
    }
  return 0;
}
