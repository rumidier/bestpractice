#include "phone.h"
#include "dlist.h"

/**
 * FILE 연다.
 * 파일을 줄단위로 읽는다 (buf)
 * 개인별로 나눈다. (line)
 * 각 개인별을 합친다 (lines)
 * lines 를 리턴 한다.
 */

char**
phone_cat_csv ()
{
  FILE *fh;
  char *line;
  char *ret; 
  char **lines;
  char buf[100];
  int buf_len = 0;
  int str_len = 0;
  int i;

  /**
   * *ret 변수는 읽어온 값의 유무를 관리 한다
   * ret으로 파일 이 끝인지 아닌지 와 오류 
   * 유무를 확인할수 있기 때문에 필요하다.
   */

  line = NULL;
  ret = NULL;
  lines = NULL;

  fh = fopen (PHONE_CSV, "r");
  if (fh == NULL)
    {
      printf ("Can not oped file[%s]\n", PHONE_CSV);
      return NULL;
    }

  while (1)
    {
      ret = fgets (buf, 100, fh);

      if (!ret)
        {
          if (!feof (fh))
            printf ("can not end file? ||%s||\n", PHONE_CSV);
          break;
        }

      buf_len = 0;
      for (i = 0; buf[i] != '\0'; i++)
        {
          if (buf[i] != '\n')
            {
              buf_len++;
            }
          else
            {
              /*
               * lines = save_line;
               * line이 끝나는 지점이다. line에 마지막 저장을 한다.
               */
              if (buf_len)
                {
                  line = (char *) realloc (line, (buf_len + str_len + 1) * sizeof (char));
                  memcpy (line + str_len, buf, buf_len);
                  line[buf_len + str_len] = '\0';

                  str_len = 0;
                  buf_len = 0;
                  lines = phone_save_in_lines (lines, line);
                  free (line);
                  line = NULL;
                  break;
                }
            }
        }

      /**
       * 한 line이 끝나지 않았지만 buf가 꽉 찼다.
       * line에 담아두자.
       */
      if (buf_len)
        {
          if (line)
            {
              line = (char *) realloc (line, (buf_len + str_len + 1) * sizeof (char));
              memcpy (line + str_len, buf, buf_len);
              line[buf_len + str_len] = '\0';
            }
          else
            {
              line = (char *) malloc (buf_len + 1 * sizeof (char));
              memcpy (line, buf, buf_len); 
              line[buf_len] = '\0';
            }

          str_len += buf_len;
        }
    }

  fclose (fh);
  return lines;
}

char**
phone_save_in_lines (char **lines,
                     char  *line)
{
  int i;
  char **new_lines;

  if (lines)
    {
      for (i = 0; lines[i] != NULL; ++i)
        ;

      new_lines = (char **) malloc ((i + 2) * sizeof (char *));
      for (i = 0; lines[i] != NULL; i++)
        {
          new_lines[i] = lines[i];
        }

      new_lines[i] = strdup (line);
      new_lines[i + 1] = NULL;

      free (lines);
    }
  else
    {
      new_lines = (char **) malloc ( 2 *sizeof (char *));
      new_lines[0] = strdup (line);
      new_lines[1] = NULL;
    }

  return new_lines;
}

void
csv_parser_debug_lines (char **lines)
{
  int i;

  if (!lines)
    return;

  for (i = 0; lines[i] != NULL; ++i)
    printf ("\n--[[[%s]]]--\n", lines[i]);
}

PhonePerson*
phone_list (char *str)
{
  PhonePerson *person;
  int str_len;
  int count = 1;

  person = (PhonePerson *) malloc (sizeof (PhonePerson) * 1);

  while ((str = strtok (str, PHONE_DELIM)) != NULL)
    {
      str_len = strlen (str);

      switch (count)
        {
        case 1:
          {
            person->eig_no = (char *) malloc (sizeof (char) * (str_len + 1));
            person->eig_no = strdup (str);
            break;
          }
        case 2:
          {
            person->ko_name = (char *) malloc (sizeof (char) * (str_len + 1));
            person->ko_name = strdup (str);
            break;
          }
        case 3:
          {
            person->en_name = (char *) malloc (sizeof (char) * (str_len + 1));
            person->en_name = strdup (str);
            break;
          }
        case 4:
          {
            person->nick_name = (char *) malloc (sizeof (char) * (str_len + 1));
            person->nick_name = strdup (str);
            break;
          }
        case 5:
          {
            person->my_tel = (char *) malloc (sizeof (char) * (str_len + 1));
            person->my_tel = strdup (str);
            break;
          }
        case 6:
          {
            person->home_tel = (char *) malloc (sizeof (char) * (str_len + 1));
            person->home_tel = strdup (str);
            break;
          }
        case 7:
          {
            person->work_tel = (char *) malloc (sizeof (char) * (str_len + 1));
            person->work_tel = strdup (str);
            break;
          }
        case 8:
          {
            person->home_addr = (char *) malloc (sizeof (char) * (str_len + 1));
            person->home_addr = strdup (str);
            break;
          }
        case 9:
          {
            person->work_addr = (char *) malloc (sizeof (char) * (str_len + 1));
            person->work_addr = strdup (str);
            break;
          }
        case 10:
          {
            person->my_email = (char *) malloc (sizeof (char) * (str_len + 1));
            person->my_email = strdup (str);
            break;
          }
        case 11:
          {
            person->work_email = (char *) malloc (sizeof (char) * (str_len + 1));
            person->work_email = strdup (str);
            break;
          }
        case 12:
          {
            person->my_homepage = (char *) malloc (sizeof (char) * (str_len + 1));
            person->my_homepage = strdup (str);
            break;
          }
        case 13:
          {
            person->twitter = (char *) malloc (sizeof (char) * (str_len + 1));
            person->twitter = strdup (str);
            break;
          }
        }

      str = NULL;
      count++;
    }

  return person;
}

void
phone_destroy (void *data)
{
  PhonePerson *person;

  person = data;

  free (person->ko_name);
  free (person->en_name);
  free (person->nick_name);
  free (person->my_tel);
  free (person->home_tel);
  free (person->work_tel);
  free (person->home_addr);
  free (person->work_addr);
  free (person->my_email);
  free (person->work_email);
  free (person->my_homepage);
  free (person->twitter);
}

int
phone_cat_command (int    argc_count,
                   char **argv_str)
{
  int i;

  if (1 < argc_count)
    {
      for (i = 1; argv_str[i] != NULL; ++i)
        {
          if (!strcmp (argv_str[i], ADD)
              || !strcmp (argv_str[i], DEL)
              || !strcmp (argv_str[i], SEARCH)
              || !strcmp (argv_str[i], CHANGE))
            return i;
        }
    }

  return 0;
}

void
phone_get_str (int    value,
               char **str_argv)
{
  int i;
  int count;

  count = 0;
  for (i = 1; str_argv[i] != NULL; ++i)
    {
      if (i != value)
        {
          get_str = (char **) realloc (get_str, sizeof (char *) * (count + 2));
          get_str[count] = strdup (str_argv[i]);
          get_str[count + 1] = NULL;

          count++;
        }
    }
}

void
phone_free_str (void)
{
  /* 세부사항 프리 해줘야 되는건가? */
  free (get_str);
}

void
phone_print (DListElmt *elmt)
{
  PhonePerson *person;

  if (elmt != NULL)
    {
      while (1)
        {
          person = elmt -> data;
          phone_person_print (person);

          if (elmt->next == NULL)
            break;
          elmt = elmt->next;
        }
    }
}

void
phone_person_print (PhonePerson *person)
{
  printf ("-----------------------------------------------------\n");
  printf ("eig_no : %s\n", person->eig_no);
  printf ("ko_name : %s\n", person->ko_name);
  printf ("en_name: %s\n", person->en_name);
  printf ("nick_name : %s\n", person->nick_name);
  printf ("my_tel : %s\n", person->my_tel);
  printf ("home_tel : %s\n", person->home_tel);
  printf ("work_tel : %s\n", person->work_tel);
  printf ("home_addr : %s\n", person->home_addr);
  printf ("work_addr : %s\n", person->work_addr);
  printf ("my_email : %s\n", person->my_email);
  printf ("work_email : %s\n", person->work_email);
  printf ("my_homepage : %s\n", person->my_homepage);
  printf ("twitter : %s\n", person->twitter);
  printf ("-----------------------------------------------------\n");

  return;
}

void
phone_sort (DList *list)
{
  PhonePerson *cur_person;
  PhonePerson *next_person;
  DListElmt *cur_elmt;
  DListElmt *next_elmt;
  DListElmt *past_elmt;
  int i;
  int size;

  size = list->size;

  for (i = 0; i < size - 1; ++i)
    {
      /**
       * list의 값이 1개 이하 일때는 동작 하지 않는다.
       * cur_elmt - 처음 시작
       * past_elmt - 처음 시작
       */
      cur_elmt = list->head;
      past_elmt = list->head;
      next_elmt = cur_elmt->next;

      cur_person = cur_elmt->data;
      next_person = next_elmt->data;

      if (next_elmt->next == NULL)
        {
          if (cur_person->eig_no > next_person->eig_no)
            {
              next_elmt->next = past_elmt;
              past_elmt->next = next_elmt;
              cur_elmt->next = NULL;
              list->head = next_elmt;
              list->tail = cur_elmt;
            }
        }
      else
        {
          while (1)
            {
              /**
               * cur > next
               */
              if (atoi(cur_person->eig_no) > atoi(next_person->eig_no))
                {
                  if (cur_elmt == list->head)
                    {
                      cur_elmt->next = next_elmt->next;
                      next_elmt->next = list->head;
                      list->head = next_elmt;
                    }
                  else if (next_elmt == list->tail)
                    {
                      next_elmt->next = past_elmt->next;
                      past_elmt->next = next_elmt;
                      cur_elmt->next = NULL;
                      list->tail = cur_elmt;
                    }
                  else
                    {
                      cur_elmt->next = next_elmt->next;
                      next_elmt->next = cur_elmt;
                      past_elmt->next = next_elmt;
                    }

                  past_elmt = next_elmt;
                  next_elmt = cur_elmt -> next;

                  if (next_elmt == NULL)
                    break;
                  cur_person = cur_elmt->data;
                  next_person = next_elmt->data;
                }
              else
                {
                  past_elmt = cur_elmt;
                  cur_elmt = next_elmt;
                  next_elmt = cur_elmt -> next;

                  if (next_elmt == NULL)
                    break;
                  cur_person = cur_elmt->data;
                  next_person = next_elmt->data;
                }
            }
        }
    }
}

DListElmt *
phone_find (DListElmt *elmt)
{
  static int i;
  int check_str;

  DListElmt *new_elmt;
  PhonePerson *person;

  check_str = 0;
  new_elmt = elmt;

  if (new_elmt == NULL)
    return NULL;
  person = new_elmt->data;

  for (i = 0; get_str[i] != NULL; ++i)
    {
      while (1)
        {
          check_str = phone_search_str (person, get_str[i]);

          if (check_str == 1)
            {
              return new_elmt;
            }

          if (new_elmt->next == NULL)
            break;

          new_elmt = new_elmt->next;
          person = new_elmt->data;
        }
    }

  i = 0;

  return NULL;
}

void
phone_search (DList *list)
{
  DListElmt *elmt;
  DListElmt *get_elmt;
  PhonePerson *person;

  elmt = list->head;
  while (1)
    {
      if (elmt == NULL)
        break;

      get_elmt = phone_find (elmt);

      if (get_elmt != NULL)
        {
          person = get_elmt->data;
          phone_person_print (person);
        }

      if (get_elmt == NULL)
        break;
      elmt = get_elmt->next;
    }

  return;
}

int
phone_search_str (PhonePerson *person,
                  char         *str)
{
  if (!strcmp (person->eig_no, str)
      || !strcmp (person->ko_name, str)
      || !strcmp (person->en_name, str)
      || !strcmp (person->nick_name, str)
      || !strcmp (person->my_tel, str)
      || !strcmp (person->home_tel, str)
      || !strcmp (person->work_tel, str)
      || !strcmp (person->home_addr, str)
      || !strcmp (person->work_addr, str)
      || !strcmp (person->my_email, str)
      || !strcmp (person->work_email, str)
      || !strcmp (person->my_homepage, str)
      || !strcmp (person->twitter, str))
    return 1;

  return 0;
}

DListElmt *
phone_past_list (DList     *list,
                 DListElmt *del_elmt)
{
  DListElmt *elmt;

  elmt = list->head;
  
  while (1)
    {
      if (elmt->next == NULL)
        break;
      if (elmt->next == del_elmt)
        return elmt;

      elmt = elmt->next;
    }

  return NULL;
}

char *
phone_eig_find (DListElmt *elmt)
{
  PhonePerson *person;
  PhonePerson *next_person;
  char *eig_num;
  char *next_num;
  int check_num;

  if (elmt->next == NULL)
    {
      eig_num = "0";
      return eig_num;
    }
  else
    {
      while (1)
        {
          if (elmt->next == NULL)
            {
              person = elmt->data;
              eig_num = person->eig_no;

              return eig_num;
            }

          person = elmt->data;
          next_person = elmt->next->data;
          eig_num = person->eig_no;
          next_num = next_person->eig_no;

          check_num = (atoi (next_num) - atoi (eig_num));
          if (check_num != 1)
            {
              return eig_num;
            }

          elmt = elmt->next;
        }
    }

  return NULL;
}

char *
phone_next_eig (char *new_eig_num,
                char *eig_num,
                int   eig_len)
{
  int i;
  int count = 0;
  int back_len;
  char *back_num;

  back_num = (char *) calloc (1, sizeof (char) * (eig_len + 2));

  back_num[count] += eig_num[eig_len - 1] + 1;

  for (i = eig_len - 1; i >= 0; --i)
    {
      if (back_num[count] >= ':')
        {
          back_num[count] -= 10;
          back_num[count + 1] += 49;
        }

      count++;
      if (i != 0)
        back_num[count] += (eig_num[i] - 48);

    }
  back_num[count + 1] = '\0';

  back_len = strlen (back_num);
  new_eig_num = (char *) realloc (new_eig_num, sizeof (char) * (back_len + 2));

  count = 0;
  for (i = (back_len - 1); i >= 0; --i)
    {
      new_eig_num[count] = back_num[i];
      count++;
    }
  new_eig_num[count] = ',';
  new_eig_num[count + 1] = '\0';

  return new_eig_num;
}
