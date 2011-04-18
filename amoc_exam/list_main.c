#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "list_head.h"
#include "list_func_head.h"

#define DIC_USAGE       \
  "옵션을 선택해 주세요\n" \
"1. 정수 추가 2. 특정 값 찾기 3. sort 4. 모두 삭제\n" \
"5. 프로그램 종료 6.현재 리스트 출력\n" \
"input option : " \

int
main (int   argc,
      char *argv[])
{
  int input_value;
  int input_id;
  char input_name[128];
  input_value = 5;


  while (1)
    {
      printf ("%s", DIC_USAGE);
      scanf ("%d", &input_value);
      /**
        "옵션을 선택해 주세요\n" \
        "1. 정수 추가 2. 특정 값 찾기 3. sort 4. 모두 삭제\n" \
        "5. 프로그램 종료 6.현재 리스트 출력\n" \
        "" \
        */

      if (input_value == 5)
        {
          fputs ("프로그램을 종료 합니다\n", stdout);
          break;
        }

      switch (input_value)
        {
        case 1:
            {
              fputs ("intput the id : ", stdout);
              scanf ("%d", &input_id);
              fputs ("intput the name : ", stdout);
              scanf ("%s", input_name);

              list_add (input_id, input_name);
              input_id = 0;
              memset (input_name, 0, strlen (input_name));
              break;
            }
        case 2:
            {
              int spec_value;
              int spec_don_check = 0;
              int spec_id = 0; //특정값 입력

              fputs ("특정 값 찾기 (0 : 삭제, 1 : 특정값 출력)", stdout);
              scanf ("%d", &spec_value);

              fputs ("찾을 id 를 입력해 주세요 : ", stdout);
              scanf ("%d", &spec_id);

              spec_rut = first_ptr;

              if (spec_value == 1)
                {
                  spec_don_check = list_spec_check (spec_rut, spec_id, spec_rut);

                  if (!spec_don_check)
                    {
                      fputs ("|----------------------------------|\n", stdout);
                      fputs ("|----------------------------------|\n\n", stdout);
                      fputs ("일치되는 id가 없습니다.\n\n", stdout);
                    }
                  else 
                    {
                      spec_print (spec_rut, spec_id);
                      fputs ("|----------------------------------|\n", stdout);
                      fputs ("모든 출력이 끝났습니다.\n\n", stdout);
                    }
                }
              else if (spec_value == 0)
                {
                  spec_don_check = list_spec_check (spec_rut, spec_id, spec_rut);

                  if (!spec_don_check)
                    {
                      fputs ("|----------------------------------|\n", stdout);
                      fputs ("|----------------------------------|\n\n", stdout);
                      fputs ("일치되는 id가 없습니다.\n\n", stdout);
                    }
                  else 
                    {
                      list_spec_delete (spec_rut, spec_id, spec_rut);
                      first_ptr = spec_rut;
                    }
                }
              else
                {
                  fputs ("잘못 입력 하셨습니다.\n", stdout);
                }

              break;
            }
        case 3:
            {
              fputs ("sort\n", stdout);
              //list_sort ();ist_func_head.h  list_
              break;
            }
        case 4:
            {
              fputs ("all delete\n", stdout);
              //list_all_delete
              break;
            }
        case 6:
            {
              struct linked_list *rut;
              rut = first_ptr;

              while (1)
                {
                  fputs ("|----------------------------------|\n", stdout);

                  list_print (rut);
                  if (rut -> next_ptr == NULL)
                    {
                      fputs ("|----------------------------------|\n", stdout);
                      fputs ("모든 출력이 끝났습니다.\n\n", stdout);

                      break;
                    }

                 rut  = rut -> next_ptr;
                }

              break;
            }
        }
    }

  return 0;
}
