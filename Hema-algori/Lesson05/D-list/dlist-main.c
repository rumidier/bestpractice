#include "phone.h"
#include "dlist.h"

int
main (int   argc,
      char *argv[])
{
  int i;
  int command_value = 0;
  char *phone_option;
  char **cat_lines;

  DList list;
  DListElmt *elmt;
  PhonePerson *person;


  command_value = phone_cat_command (argc, argv);

  if (command_value == 0)
    {
      if (argc <= 1)
        {
          fputs ("too few command\n", stdout);
          fputs (PHONE_INT_USAGE, stdout);

          exit (EXIT_FAILURE);
        }
      else
        {
          fputs ("invalid input\n", stdout);
          fputs (PHONE_INT_USAGE, stdout);

          exit (EXIT_FAILURE);
        }
    }

  if (argc == 2)
    {
      fputs ("too few command\n", stdout);
      fputs (PHONE_INT_USAGE, stdout);

      exit (EXIT_FAILURE);
    }

  if (command_value)
    {
      phone_option = argv[command_value];
      get_str = (char **) malloc (sizeof (char *));
      get_str[0] = NULL;
      phone_get_str (command_value, argv);
    }
  else
    {
      fputs (PHONE_INT_USAGE, stdout);

      exit (EXIT_FAILURE);
    }

  cat_lines = phone_cat_csv ();

  if (!cat_lines)
    {
      printf ("why return cat_lines\n");
      fputs ("help message print\n", stdout);

      exit (EXIT_FAILURE);
    }

  dlist_init (&list, phone_destroy);
  for (i = 0; cat_lines[i] != NULL; ++i)
    {
      char *token;

      token = cat_lines[i];

      person = phone_list (token);
      elmt = list.head;
      dlist_ins_next (&list, elmt, person);
    }
  phone_sort (&list);

  elmt = list.head;
  phone_print (elmt);

  if (!strcmp (ADD, phone_option))
    {
      int eig_len;
      char *add_token;
      char *eig_num;

      for (i = 0; get_str[i] != NULL; ++i)
        {
          elmt = list.head;
          eig_num = phone_eig_find (elmt);

          if (eig_num == NULL)
            {
              break;
            }
          else
            {
              char *new_eig_num;
              int add_token_len;
              int get_str_len = 0;

              new_eig_num = (char *) malloc (sizeof (char));
              eig_len = strlen (eig_num);
              phone_next_eig (new_eig_num, eig_num, eig_len);

              add_token = strdup (new_eig_num);
              add_token_len = strlen (add_token);
              get_str_len = strlen (get_str[i]);

              add_token = (char *) realloc (add_token, \
                           sizeof (char) * ((add_token_len) + (get_str_len) + 1));
              strcat (add_token, get_str[i]);
              add_token[add_token_len + get_str_len] = '\0';

              person = phone_list (add_token);
              elmt = list.head;
              dlist_ins_next (&list, elmt, person);
              free (new_eig_num);
            }

          phone_sort (&list);
        }

      elmt = list.head;
      phone_print (elmt);
    }
  else if (!strcmp (DEL, phone_option))
    {
      int i;
      DListElmt *del_elmt;

        for (i = 0; get_str[i] != NULL; ++i)
          {
            elmt = list.head;
            while (1)
              {
                if (elmt == NULL)
                  break;
                del_elmt = phone_find (elmt);

                if (del_elmt)
                  {
                    int value;
                    void *data;

                    DListElmt *past_elmt;

                    person = del_elmt->data;
                    phone_person_print (person);

                    fputs ("내용을 삭제 하시겠습니까?(y = 1 | n = 0) : ", stdout);
                    scanf ("%d", &value);
                    getchar ();

                    if (value)
                      {
                        past_elmt = phone_past_list (&list, del_elmt);

                        dlist_remove (&list, past_elmt, (void **)&data);
                        phone_destroy (data);
                        printf ("삭제 되었습니다.\n");
                      }
                    elmt = del_elmt->next;
                  }
                else if(del_elmt == NULL)
                  {
                    elmt = elmt->next;
                  }
              }
          }

      elmt = list.head;
      phone_print (elmt);
    }
  else if (!strcmp (SEARCH, phone_option))
    {
      phone_search (&list);
      printf ("===============================\n");
      printf ("debug\n");
      printf ("===============================\n");
    }
  else if (!strcmp (CHANGE, phone_option))
    {
    }
  /*
   * 4월29일 오후 5:38
   * option + command + linked + dlist_sort ->> ?
   */

  phone_free_str ();
  dlist_destroy (&list);
  fputs ("END!!!!!!!!!\n", stdout);
  //cat_lists free!! 

  return 0;
}
