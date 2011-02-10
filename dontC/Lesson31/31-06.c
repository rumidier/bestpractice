#include <stdio.h>
#include <string.h>

#define NAME_LEN 30
#define PID_LEN  15

struct __person
{
  char name[NAME_LEN];
  char ID[PID_LEN];
  unsigned int age;
};

typedef struct __person person;

void
show_person_data (person * ptr)
{
  printf ("이름 : %s \n", (*ptr).name);
  printf ("주민등록 번호 : %s \n", (*ptr).ID);
  printf ("나이 : %u \n", ptr -> age);
}

int
main (int   argc,
      char *argv[])
{
  person jongsoo;
  person copyman;
  person *personptr;

  strcpy (jongsoo.name, "한종수");
  strcpy (jongsoo.ID, "900218-1012589");
  jongsoo.age = 20;

  copyman = jongsoo;
  personptr = &copyman;

  show_person_data (personptr);

  return 0;
}
