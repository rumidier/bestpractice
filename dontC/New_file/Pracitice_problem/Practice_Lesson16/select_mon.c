#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int my_money;
  int movie;

  int shrimp_ggang;
  int coca_colra;
  int full_money;
  int candy;
  int i, j, k;

  my_money = 7000;
  movie = 2000;
  my_money -= movie;

  shrimp_ggang = 900;
  coca_colra = 750;
  candy = 200;

  for (i = 1; i <= (my_money / shrimp_ggang); i++)
    {
      full_money = 0;
      for (j = 1; j <= (my_money / coca_colra); j++)
        {
          for (k = 1; k <= (my_money / candy); k++)
            {
              full_money = (i * shrimp_ggang) + (j * coca_colra) + (k * candy);
              if (full_money == 5000)
                printf ("새우깡 %d개, 콜라 %d개, 츕파츕스 %d개\n", i, j, k);
            }
        }
    }
  printf ("몇개씩 사시겠습니까?\n");

  return 0;
}
