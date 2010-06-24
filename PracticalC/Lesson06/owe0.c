#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char line[80];
  int balance_owed;

  printf ("Enter number of dollars owed:");
  fgets (line, sizeof (line), stdin);
  sscanf (line, "%d", &balance_owed);

  if (balance_owed == 0)
    printf ("You owe nothing.\n");
  else
    printf ("You owe %d dollars.\n", balance_owed);

  return 0;
}
