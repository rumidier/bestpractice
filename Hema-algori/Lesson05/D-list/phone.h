#ifndef     PHONE_H
#define     PHONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

#define     PHONE_MAX_LEN     256
#define     PHONE_CSV         "linked-phone.csv" 
#define     PHONE_DELIM       ","
#define     ADD               "add"
#define     DEL               "del"
#define     CHANGE            "change"
#define     SEARCH            "search"
#define     PHONE_INT_USAGE          \
    "Usage:\n" \
    "     phone <command> [string]\n" \
    "\n" \
    "Command:\n" \
    "    add <string>\n" \
    "        입력된 정보를 저장 합니다.\n" \
    "\n" \
    "    del <string>\n" \
    "        입력된 정보의 개인정보 모두를 삭제 합니다.\n" \
    "\n" \
    "    search <string>\n" \
    "        입력된 정보에 대해 출력 합니다.\n" \
    "\n" \
    "    change \n" \
    "        미구현.\n"

typedef struct _PhonePerson {
  char *eig_no;
  char *ko_name;
  char *en_name;
  char *nick_name;
  char *my_tel;
  char *home_tel;
  char *work_tel;
  char *home_addr;
  char *work_addr;
  char *my_email;
  char *work_email;
  char *my_homepage;
  char *twitter;
} PhonePerson;

int
phone_cat_command (int,
                   char **);

char **
phone_cat_csv ();

char **
phone_save_in_lines (char **lines,
                     char *line);

PhonePerson *
phone_list (char *);

void
phone_destroy (void *data);

void
phone_print (DListElmt *elmt);

void
phone_person_print (PhonePerson *person);

void
phone_sort (DList *list);

char **get_str;

void
phone_free_str (void);

void
phone_get_str (int ,
               char **);

DListElmt *
phone_find (DListElmt *elmt);

void
phone_search (DList *list);

int
phone_search_str (PhonePerson *person,
                  char        *str);

DListElmt *
phone_past_list (DList *list, DListElmt *del_elmt);

char *
phone_eig_find (DListElmt *elmt);

char *
phone_next_eig (char *, char *, int);

#endif
