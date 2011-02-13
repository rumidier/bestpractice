#include <stdio.h>

#define NAME_LEN  30
#define PID_LEN   15

struct __person
{
  char name[NAME_LEN];
  char ID[PID_LEN];
  unsigned int age;
};

typedef struct __person  person;

void
show_person_data (person *ptr)
{
  printf ("이름 : %s \n", (*ptr).name);
  printf ("주민등록 번호 : %s \n", (*ptr).ID);
  printf ("나이 : %u \n\n", ptr -> age);
}

int
main (int   argc,
      char *argv[])
{
  person jongsoo = {"한종수", "900218-1012589", 20};
  person sungeun = {"이성은", "910218-1012589", 19};

  show_person_data (&jongsoo);
  show_person_data (&sungeun);

  return 0;
}
