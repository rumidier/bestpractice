#include <stdio.h>
#include <stdlib.h>

int
main (int   argc,
      char *argv[])
{
  int number_to_guess;
  int low_limit;
  int high_limit;
  int guess_count;
  int player_number;
  char line[100];

  while (1) {
    number_to_guess = rand () % 100 + 1;

    low_limit = 0;
    high_limit = 100;
    guess_count = 0;

    while (1) {
      printf ("Bounds %d - %d\n", low_limit, high_limit);
      printf ("Value? %d\n", guess_count);
      ++guess_count;

      fgets (line, sizeof (line), stdin);
      sscanf (line, "%d", &player_number);

      if (player_number == number_to_guess)
        break;

      if (player_number < number_to_guess)
        low_limit = player_number;
      else
        high_limit = player_number;
    }
    printf ("Bingo\n");
  }

  return 0;
}
