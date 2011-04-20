#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



typedef struct phone_point
{
  int list_size;

  struct phone_list *head;
  struct phone_list *tail;
} PhonePoint;

typedef struct phone_list
{
  int eig_no;

  Name *in_name;
  Phone *in_phone;
  Address *in_addr;

  struct phone_list *next;
} PhoneList;

void
list_init (PhoneList *list, PhonePoint *point);

PhoneList *fir_list;
PhonePoint *fir_point;

typedef struct name
{
  char *ko_name;
  char *en_name;
  char *nick_name;
} Name;

typedef struct phone_num
{
  int *phone_number;
  int *home_number;
  int *work_number;
} Phone;

typedef struct address
{
  char *home_addre;
  char *work_addre;
  char *my_email;
  char *work_email;
  char *e_home;
  char *twitter;
} Address;

int
main (int   argc,
      char *argv[])
{
  list_init (fir_list, fir_point);

  return 0;
}

void
list_init (PhoneList *list, PhonePoint *point)
{
  point -> head = (PhonePoint *) malloc (sizeof (PhonePoint));
  point -> tail = (PhonePoint *) malloc (sizeof (PhonePoint));

  point -> head = list;
  point -> tail = tail;
}
