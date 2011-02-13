#include <stdio.h>

#define ARRY_LEN    3
#define NAME_LEN    30
#define PID_LEN     15

typedef struct __person
{
  char name[NAME_LEN];
  char ID[PID_LEN];
  unsigned int age;
} person;

void show_person_data (person *ptr);

int
main (int   argc,
      char *argv[])
{
  int i;

  person personarr [ARRY_LEN] = {
      {"한종수", "900218-1012589", 20},
      {"이성은", "910218-1012589", 19},
      {"윤지민", "930218-1012589", 17},
  };

  for (i = 0; i < ARRY_LEN; i++)
    {
      show_person_data (&personarr[i]);
    }

  return 0;
}

void
show_person_data (person *ptr)
{
  printf ("이름 : %s \n", (*ptr).name);
  printf ("주민 등록 번호 : %s \n", (*ptr).ID);
  printf ("나이 : %u \n\n", ptr -> age);
}
