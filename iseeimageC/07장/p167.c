#include <stdio.h>

typedef struct _PROFILE {
  char name[40];
  int age;
} PROFILE;

int
main (int argc, char *argv[])
{
  PROFILE prof [2] = {
      {"juhyun", 23},
      {"jiwon", 31}
  };

  int i;
  for (i = 0; i < 2; i++)
    printf ("%s님은 %d살입니다.\n",
            prof[i].name, prof[i].age);

  return 0;
}
