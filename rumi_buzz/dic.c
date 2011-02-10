#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>


#define DIC_COMMAND_ADD         "add"
#define DIC_COMMAND_SEARCH      "search"
#define DIC_COMMAND_REMOVE      "remove"
#define DIC_COMMAND_BOOKMARK    "bookmark"
#define DIC_COMMAND_HELP        "help"
#define DIC_COMMAND_LIST        "list"
#define FULL_LEN                 1024 * 1024

#define DIC_USAGE       \
  "Usage:\n" \
"   dic bookmark <command> <word>\n" \
"   dic bookmark -b <path> <commnad> <word>\n" \
"   dic bookmark <command> <word> -b <path>\n" \
"\n" \
"Command:\n" \
"   add <word> <explainatio>\n" \
"       word에 대한 explaination 을 추가 합니다\n" \
"\n" \
"   search <word>\n" \
"       search 는 word 를 찾아 설명합니다\n" \
"\n"  \
"   remove <word>\n" \
"       word에 대한 내용을 data에서 삭제합니다\n" \
"\n" \
"   help\n" \
"      dic에 대한 사용법을 설명 합니다.\n" \
"\n" \
"   -s <경로>\n" \
"       -s은 경로에 해당하는 data를 읽어 옵니다. \n" \
"\n" \
"   bookmark add <word>\n" \
"       일치 하는 단어가 없다면 list에 단어를 추가 합니다.\n" \
"\n" \
"   bookmark remove <word>\n" \
"       단어를 list에서 삭제합니다\n" \
"\n" \
"   dic bookmark help\n" \
"      bookmark에 대한 사용법을 설명 합니다.\n" \
"\n" \
"   -b <경로>\n" \
"       -b경로에 대한 list를 읽어 옵니다. \n" \
"\n" \
/**************************************************************************************
  typedef int full_message_count;
  -> typedef int full_message_count ->>> full_message_count FMC;
  명령어가 너무 길어서 FMC로 변환하였습니다.

  char *
  serv_in_explan;
  -> serv에 command가 search일시 explan를 담아 주기 위하여 선언 되었습니다.

  static void
  dic_error_exit (const char *msg);
  -> msg 가 bookmark 인지 검사하여 bookmark 라면 bookmark 관련 help 출력하며
  bookmark가 아니라면 일반적인 help옵션과 S-PATH 관련 help를 출력합니다.

  static int
  num_check = -1;
  -> 수정 하고 싶은 부분. node 에서 word를 검사 할대 쓰이며 기본은 -1 word와 노드에 단어가
  치 한다면 1을 반환 합니다.

  static int 
  dic_search_check (char  *fp_txt,
  char  *in_word,
  char  *check_bookmark);
  -> 경로에 있는 파일을 열어서 단어를 찾아 존재 유무를 검사 한다.
  fp_txt : b_patn, s_path, file 의 경로를 의미 합니다.
  in_word : 입력된 word 값.
  check_bookmark : bookmark 옵션인지 검사합니다.
  int형 반환값을 반환 하며 bookmark옵션이 없을 시 explan 값또한 저장 합니다.

  static void
  dic_add (char *dic_word,
char *fp,
     char *in_plan);
-> 임시(fp나 경로지정 문자열) 파일을 오픈한후 dic_word|in_plan 형식으로 붙여 넣습니다.
(command가 add일시 동작 하며 그 이전에 in_word의 존재 여부를 판가름 하여
 이전에 저장 되지 않았을 경우에만 동작 하게 됩니다.)

struct WORD {
  char *word_name;
  char *explain;
} DICTIONARY[0];
struct WORD *dic_save_data = DICTIONARY;

struct node {
  struct node *left;
  struct node *right;
  char        *word;
};
static struct node *root = NULL;

char *
save_string (char *string);
-> 움.......................왜 전역변수가......>?

void
dic_enter (struct  node  **node,
           char           *word);
-> node에 word를 정렬 시킵니다.

char *
dic_remove_word (char *buf);
->buf ('|'(bookmark 옵션 없을시) or '\n'(bookmark 옵션이 있을시)가 끝을 알림) 문자열 에서
word 부분만 추출하여 word를 리턴하여 줍니다.
char *buf : 사전에서 하나의 단어와 그 뜻을 담은 문자열 입니다. (끝은 '|' or '\n' 구분 합니다)

static void
dic_scan (char *name,
          char *in_word,
          char *check_bookmark);
-> name (fp의 경로)에 있는 파일을 오픈 하여 단어와 뜻을 저장 한다.
char *name : file의 경로
char *in_word : 입력된 단어
char *check_bookmark : bookmark옵션 검색

static void
dic_book_remove (struct node *top,
                 char *in_word);
-> node 에 저장 되어 있는 단어들을 비교하여 입력된 word만 제외하고 임시저장한후 본 워드장과 이름을 바꾸게 됩니다.
struct node *top : noed에 있는 최상 단어 입니다.
char *in_word : 입력된 단어 입니다.

static void
print_tree (struct node *top,
            FILE *fp,
            char *bookmark);
-> node에 저장 되어 있는 단어들을 정렬 하는 함수입니다. (command 입력시 list라면 단어들을 출력
                                                         command가 remove라면 단어를 제외하고 저장)

static int 
dic_book_search (struct node *top,
                 char        *in_word,
                 int         check);
-> node 에 저장되어 있는 단어들을 정렬 시키게 됩니다.

static void
error_message (char *message);
-> error_message 출력

******************************************************************************************/
typedef int full_message_count;
static char **input_message;
static int dic_cat_command (char *bookmark_command, char *input_message);

char *serv_in_explan;

static int
num_check = -1;

static void
dic_input_message (int    argc,
                   char **argv,
                   int    argc_count); 

static void
dic_input_message (int    argc,
                   char **argv,
                   int    argc_count)
{
  int i;
  int count;

  count = 0;

  for (i = argc_count; i < argc; i++)
    {
      input_message = (char **) realloc (input_message, (count + 2) * sizeof (char *));
      input_message[count] = argv [i];
      input_message[count + 1] = NULL;
      count++;
    }
}

static void
dic_serv_input_message (int    len,
                        char  *message) 
{
  char *token = NULL;
  char *sepa = "_";
  int count;

  token = (char *) realloc (token, (256 * sizeof (char)));
  count = 0;

  token = strtok (message, sepa);

  if (token == NULL)
    {
      input_message[0] = NULL;
    }
  else if (token != NULL)
    {
      input_message = (char **) realloc (input_message, (len + 2) * sizeof (char *));
      input_message[count] = (char *) realloc (NULL, (strlen (token) * sizeof (char)));
      strcpy (input_message[count], token);
      input_message[count + 1] = NULL;
    }

  while ((token = strtok (NULL, sepa)) != NULL)
    {
      count++;
      input_message[count] = (char *) realloc (NULL, (strlen (input_message[count - 1]) + strlen (token)) * sizeof (char));
      strcpy (input_message[count], token);
      input_message[count + 1] = NULL;
    }
}

static int 
dic_search_check (char  *fp_txt,
                  char  *in_word,
                  char  *check_bookmark);

static void
dic_add (char *dic_word,
         char *fp,
         char *in_plan);

struct WORD {
  char *word_name;
  char *explain;
} DICTIONARY[0];
struct WORD *dic_save_data = DICTIONARY;

struct node {
  struct node *left;
  struct node *right;
  char        *word;
};

static struct node *root = NULL;

static void
dic_error_exit (const char *msg)
{
  printf ("%s", DIC_USAGE);

  exit (EXIT_FAILURE);
}

static char *
save_string (char *string)
{
  char *new_string;

  new_string = (char *) malloc ((unsigned) (strlen (string) + 1));

  if (new_string == NULL)
    dic_error_exit (NULL);
  strcpy (new_string, string);

  return (new_string);
}

static void
dic_enter (struct  node  **node,
           char           *word)
{
  int result;
  char *save_string ();
  void dic_error_exit ();

  if ((*node) == NULL)
    {
      (*node) = malloc (sizeof (struct node));

      if ((*node) == NULL)
        dic_error_exit (NULL);

      (*node) -> left = NULL;
      (*node) -> right = NULL;
      (*node) -> word = save_string (word);

      return;
    }

  result = strcmp ((*node) -> word, word);

  if (result == 0)
    return;

  if (result < 0)
    dic_enter (&(*node) -> right, word);
  else
    dic_enter (&(*node) -> left, word);
}

static char *
dic_remove_word (char *buf)
{
  int buf_len, word_len;
  int i;
  char *return_word;

  buf_len = strlen (buf);
  word_len = 0;

  for (i = 0; i < buf_len; i++)
    {
      if (buf[i] == '|' || buf[i] == '\n')
        {
          break;
        }
      else
        {
          word_len++;
        }
    }

  return_word = (char *) malloc( sizeof(char) * word_len + 1);
  memset (return_word, '\0', word_len + 1);

  for (i = 0; i < word_len; i++)
    {
      return_word[i] = buf[i];
    }

  return return_word;
}

static void
dic_scan (char *name,
          char *in_word,
          char *check_bookmark)
{
  FILE *in_file;
  char *buf;
  char *return_value;
  int fpos_begin;
  int fpos_last;
  int buf_size;
  long tmp;

  buf_size = 0;
  fpos_begin = 0;
  fpos_last = 0;

  in_file = fopen (name, "r");// name = dic.test

  if (in_file == NULL)
    {
      fprintf (stderr, "Error:Unable to open%s\n", name);
      exit (EXIT_FAILURE);
    }

  while (1)
    {
      fpos_begin = ftell (in_file);
      fseek (in_file, 1, SEEK_CUR);

      if (getc (in_file) == EOF)
        break;

      while (1)
        {
          tmp = fgetc (in_file);
          if (tmp != '\n')
            {
              continue;
            }
          else
            {
              fpos_last = ftell (in_file);
              break;
            }
        }

      buf_size = fpos_last - fpos_begin;
      buf = (char *) malloc (sizeof (char) * buf_size);

      fseek (in_file, - buf_size, SEEK_CUR);
      fgets (buf, buf_size, in_file);

      if (strlen (buf) == 1)
        continue;

      if (!strcmp (check_bookmark, "bookmark"))
        {
          return_value = dic_remove_word (buf);
          dic_enter (&root, return_value);
        }
      else if (strcmp (check_bookmark, "bookmark"))
        {
          return_value = dic_remove_word (buf);

          if (strcmp (return_value, in_word))
            {
              dic_search_check (name, return_value, check_bookmark);
              dic_add (return_value, "abc.txt", dic_save_data -> explain);
            }
          else
            {
              continue;
            }

        }
    }
  if (strcmp (check_bookmark, "bookmark"))
    {
      remove ("dic.test");
      rename ("abc.txt", "dic.test");
    }

  fclose (in_file);
}

static void
dic_book_remove (struct node *top,
                 char  *in_word)
{
  FILE *save_txt;

  if (top == NULL)
    return;

  save_txt = fopen ("save.txt", "a+");

  if (save_txt == NULL)
    {
      exit (EXIT_FAILURE);
    }
  dic_book_remove (top -> left, in_word);

  if (strcmp (top -> word, in_word))
    fprintf (save_txt, "%s\n", top -> word);
  dic_book_remove (top -> right, in_word);
}

static void
print_tree (struct node *top,
            FILE        *fp,
            char        *bookmark)
{
  FILE *abc;

  abc = fopen ("list.dat", "a");

  if (abc == NULL)
    return;
  if (top == NULL)
    return;

  print_tree (top -> left, fp, bookmark);

  if (!strcmp (bookmark, "bookmark"))
    printf ("%s\n", top -> word);
  else if (strcmp (bookmark, "bookmark"))
    fprintf (abc, "%s\n", top -> word);

  print_tree (top -> right, fp, bookmark);
}

static int 
dic_book_search (struct node *top,
                 char        *in_word,
                 int          check)
{
  int num;
  num = check;

  if (top == NULL)
    return num_check; 

  dic_book_search (top -> left, in_word, num);
  num = strcmp (in_word, top -> word);

  if (num == 0)
    {
      num_check = 1;
    }

  dic_book_search (top -> right, in_word, num);

  return num_check;
}

static int 
dic_search_check (char  *fp_txt,
                  char  *in_word,
                  char  *check_bookmark)
{
  FILE *fp;
  char *buf;
  int i, j;
  int fpos_begin;
  int fpos_last;
  int buf_size;
  long tmp;

  fp = fopen (fp_txt, "r");

  buf_size = 0;
  fpos_begin = 0;
  fpos_last = 0;

  while (1)
    {
      fpos_begin = ftell (fp);
      fseek (fp, 1, SEEK_CUR);

      if (getc (fp) == EOF)
        break;

      while(1)
        {
          tmp = fgetc (fp);

          if (tmp != '\n')
            {
              continue;
            }
          else
            {
              fpos_last = ftell (fp);
              break;
            }
        }

      buf_size = fpos_last - fpos_begin;
      buf = (char *) malloc (sizeof (char) * buf_size);

      fseek (fp, -buf_size,  SEEK_CUR);
      fgets (buf, buf_size, fp);

      for (i = 0; i < buf_size; i++)
        {
          if (!strcmp (check_bookmark, "bookmark"))
            {
              if (buf[i] == in_word[i])
                {
                  if ((buf[i + 1] == '\n') && (in_word[i + 1] == '\n'))
                    {
                      return 1;
                    }
                  else
                    {
                      memset (buf, '\0', strlen (buf));
                      break;
                    }
                }
            }
          else if (strcmp (check_bookmark, "bookmark"))
            {
              if (buf[i] == in_word[i])
                {
                  if ((buf[i + 1] == '|') && (in_word [i + 1] == '\0'))
                    {
                      int k;

                      k = 0;
                      dic_save_data -> explain = (char *) malloc (sizeof (char) * buf_size);

                      for (j = i + 2; j < buf_size; j++)
                        {
                          dic_save_data -> explain[k] = buf[j];
                          k++;
                        }
                      free (buf);

                      return 1;
                    }
                }
              else
                {
                  break;
                }
            }
        }
    }
  free (buf);

  return -1;
}

static void
dic_add (char *dic_word,
         char *fp,
         char *in_plan)
{
  FILE *dic_add_fp;

  dic_add_fp = fopen (fp, "a");

  if (fp == NULL)
    exit (EXIT_FAILURE);

  if (in_plan == NULL)
    {
      fprintf (dic_add_fp, "%s\n", dic_word);
    }
  else
    {
      fprintf (dic_add_fp, "%s|", dic_word);
      fprintf (dic_add_fp, "%s\n", in_plan);
    }

  fclose (dic_add_fp);
}

static int
dic_cat_command (char *bookmark_command,
                 char *input_message)
{
  if (!strcmp (input_message, DIC_COMMAND_LIST) || !strcmp (input_message, DIC_COMMAND_HELP))
    {
      if (!strcmp (input_message, DIC_COMMAND_LIST))
        {
          return 1; //1 : list
        }
      else
        {
          return 2; // 2: help
        }
    }
  else if (!strcmp (input_message, DIC_COMMAND_ADD) ||!strcmp (input_message, DIC_COMMAND_SEARCH) ||
           !strcmp (input_message, DIC_COMMAND_REMOVE))
    {
      if (!strcmp (input_message, DIC_COMMAND_ADD))
        {
          return 3; // 3 : add
        }
      else
        {
          return 4; // 4 : search remove
        }
    }
  else if (input_message != NULL)
    {
      return 5;//5 :  NULL, error
    }
  else
    {
      return 5;//5 :  NULL, error
    }
}

static void
error_message (char *message)
{
  fputs (message, stderr);
  fputc ('\n', stderr);
  exit (EXIT_FAILURE);
}



int
main (int   argc,
      char *argv[])
{
  FILE *fp;
  char *path_command; //path_command 는 -s 에서 쓰이기 위해 작성되었다
  char *in_word;
  char *command;
  char *bookmark_command;
  char *s_path;
  char *b_path;
  char *ip_num;
  char *p_num;
  int c_exist;
  int s_exist;
  int b_exist;
  int p_exist;
  int server_exist;
  int book_exist;
  int return_search;
  int opt;
  int argc_count;
  int check_list;
  int bookmark_value;
  int bookmark_count;

  bookmark_count = 0;
  bookmark_value = 0;
  server_exist = 0;
  c_exist = 0;
  argc_count = 0;
  book_exist = 0;
  return_search = 0;
  p_num = 0;
  s_exist = 0;
  b_exist = 0;

  if (argc < 2)
    {
      dic_error_exit ("Command is needed");
    }
  /**
   * -d : dic.server 활성화
   * -p <port num> : -p 옵션과 포트 넘버
   * -c : dic.client 활성화
   * ./dic -d -p <port num>
   * ./dic -c <ip num> -p <port num>
   */
  /**
   * getopt : -s "path", -b "path"
   for (k = 0; k <= strlen (message_full_string); k++)
   {
   printf ("[%c]", message_full_string[k]);
   }
   printf ("len [%d]\n", strlen (message_full_string));
   * s_exist = -s의 존재 유무 확인  s_path = -s 사용시 경로를 저장한다.
   * b_exist = -b의 존재 유무 확인  b_path = -b 사용시 경로를 저장한다.
   * 2011.2.07 -c,옵션은 test_client.c 로 구현 되어 있음.
   */
  int opt_count;
  opt_count = 1;

  while ((opt = getopt (argc, argv, "dc:p:s:b:")) != -1)
    {
      switch (opt)
        {
        case 'b':
            {
              b_exist = 1;
              b_path = (char *) realloc (NULL, sizeof (char) * (strlen (optarg)));
              b_path = optarg;
              opt_count += 2;
              break;
            }
        case 'c':
            {
              c_exist = 1;
              ip_num = (char *) realloc (NULL, sizeof (char) * (strlen (optarg)));
              ip_num = optarg;
              opt_count += 2;
              break;
            }
        case 'd':
            {
              server_exist = 1;
              opt_count++;
              break;
            }
        case 'p':
            {
              p_exist = 1;
              p_num = (char *) realloc (NULL, sizeof (char) * (strlen (optarg)));
              p_num = optarg;
              opt_count += 2;
              break;
            }
        case 's':
            {
              s_exist = 1;
              s_path = (char *) realloc (NULL, sizeof (char) * (strlen (optarg)));
              s_path = optarg;
              opt_count += 2;
              break;
            }
        }
    }
  int clnt_sock;
  char *full_message;

  input_message = (char **) malloc (sizeof (char));//input_message는 command, word, explan을 관리하는 배열
  input_message[0] = NULL;

  if (server_exist == 1)
    {
      int serv_sock;
      int str_len;
      int full_message_len;
      int k2;
      int message_count;
      int str_count;
      char *result_message;
      char message[256];

      struct sockaddr_in serv_adr;
      struct sockaddr_in clnt_adr;

      full_message_count FMC;
      full_message_len = 0;
      str_count = 0;
      socklen_t clnt_adr_sz;

      serv_sock = socket (PF_INET, SOCK_STREAM, 0);

      if (serv_sock == -1)
        error_message ("socket () error!");

      memset (&serv_adr, 0, sizeof (serv_adr));
      serv_adr.sin_family = AF_INET;
      serv_adr.sin_addr.s_addr = htonl (INADDR_ANY);
      serv_adr.sin_port = htons (atoi (p_num));

      if (bind (serv_sock, (struct sockaddr *) &serv_adr, sizeof (serv_adr)) == -1)
        error_message ("bind () error!");
      if (listen (serv_sock, 5) == -1)
        error_message ("listen () error!");

      full_message = (char *) realloc (NULL, sizeof (char));
      full_message = NULL;
      clnt_sock = accept (serv_sock, (struct sockaddr *) &clnt_adr, &clnt_adr_sz);

      if (clnt_sock == -1)
        error_message ("accept () error");
      else
        printf ("Connected client\n");

      while (1)
        {
          memset (message, 0, 256);
          str_len = read (clnt_sock, message, 256);

          if (str_len == 0)
            break;

          message[str_len] = '\0';
          full_message_len += str_len;
          full_message = (char *) realloc (full_message,(full_message_len) * sizeof (char));
          strcat (full_message, message);

          if (full_message[full_message_len - 1] == '\n')
            break;
        } 
      printf ("%s\n", full_message);

      message_count = 0;
      result_message = (char *) calloc (sizeof (result_message), sizeof (char) * (full_message_len));

      //typedef int full_message_count >> full_message_count FMC;
      for (FMC = 0; FMC < full_message_len; FMC++)
        {
          if (full_message[FMC] == '"')
            {
              for (k2 = FMC; k2 < full_message_len; k2++, FMC++)
                {
                  if (full_message[k2] == '"')
                    {
                      continue;
                    }
                  else if (full_message[k2] == '\n')
                    {
                      break;
                    }
                  else
                    {
                      result_message[message_count] = full_message[k2];
                      message_count++;
                    }
                }
            }
          else if (full_message[FMC] == ' ')
            {
              result_message[message_count] = '_';
              message_count++;
              str_count++;
            }
          else if (full_message[FMC] == '\n')
            {
              result_message[message_count] = '\0';
              message_count++;
            }
          else
            {
              result_message[message_count] = full_message[FMC];
              message_count++;
            }
        }
      result_message[message_count] = '\0';

      dic_serv_input_message (str_count, result_message);
    }
  else if (server_exist == 0)
    {
      dic_input_message (argc, argv, opt_count);
    }
  /**
   * bookmark 옵션 이 적용될시
   * s_exist 옵션이 있다면 종료한다.
   * b_exist 옵션유무에 따라 list.test파일 위치가 틀려진다.
   * dic_book_search 옵션으로 word가 기존에 있는지 없는지 검사후
   * -1 이나 1 값을 반환한다.
   */
  int input_count;
  int command_check;
  char *error_message;
  command_check = 5;
  input_count = 0;

  if (input_message[input_count] ==  NULL || input_message[input_count + 1] ==  NULL)
    {
      if (server_exist != 1)
        dic_error_exit ("Command is needed");
      else if (server_exist == 1)
        {
          //write (clnt_sock, DIC_USAGE, strlen (DIC_USAGE));
          //close (clnt_sock);
          error_message = "Error:Unable to open\n";
          printf ("[%s]\n", error_message);
          write (clnt_sock, error_message, strlen (error_message) + 1);
          return 2;
        }
    }

  if (!strcmp (input_message[input_count], DIC_COMMAND_BOOKMARK))
    {
      bookmark_value = 1;
      bookmark_command = input_message[input_count];
      input_count++;
      command_check = dic_cat_command (bookmark_command, input_message[input_count]);

      if (command_check == 1)//list
        {
          check_list = 1;
          command = input_message[input_count];
          in_word = "don't word";
        }
      else if (command_check == 2)//help
        {
          command = input_message[input_count];
          in_word = NULL;
        }
      else if (command_check == 3)//add
        {
          command = input_message[input_count];
          in_word = input_message[input_count + 1];
        }
      else if (command_check == 4)//remove
        {
          command = input_message[input_count];
          in_word = input_message[input_count + 1];
        }
      else if (command_check == 5)//NULL, error
        {
          command = NULL;
          in_word = NULL;
          //    NULL, error;
        }

      if (b_exist == 0)
        {
          char *save_argv;
          int path_len;
          int check_slah;
          int y;

          path_len = strlen (argv[0]);
          save_argv = argv[0];
          check_slah = 0;

          for (y = 0; y < path_len; y++)
            {
              if (save_argv[y] == '/')
                check_slah++;
            }
          char save_path_command[check_slah + 1];

          for (y = 0; y < check_slah + 1; y++)
            {
              save_path_command[y] = save_argv[y];
            }

          save_path_command[y] = '\0';
          b_path = (char *) malloc (sizeof (char) * (check_slah + 10));
          sprintf (b_path, "%slist.dat", save_path_command);

          path_command = b_path;//data file 은 내위치 에 없으면 , 실행 파일 위치에서 해야한다 [argv[0]]

          fp = fopen (path_command, "r");

          if (fp == NULL)
            {
              path_command = "list.dat";
              fp = fopen (path_command, "a+");

              if (fp == NULL)
                {
                  printf ("Could not read the file\n");
                  exit (EXIT_FAILURE);
                }
            }
          fclose (fp);

          if (in_word == NULL)
            dic_error_exit (bookmark_command);
          dic_scan (path_command, in_word, bookmark_command);
          return_search = dic_book_search (root, in_word, -1);
        }
      else if (b_exist == 1)
        {
          path_command = b_path;

          fp = fopen (path_command, "r");

          if (fp == NULL)
            {
              path_command = "list.dat";
              fp = fopen (path_command, "a+");

              if (fp == NULL)
                {
                  printf ("Could not read the file\n");
                  exit (EXIT_FAILURE);
                }
            }
          fclose (fp);

          if (in_word == NULL)
            dic_error_exit (bookmark_command);
          dic_scan (path_command, in_word, bookmark_command);
          return_search = dic_book_search (root, in_word, -1);
        }
    }
  else if (strcmp (input_message[input_count], DIC_COMMAND_BOOKMARK))
    {
      bookmark_command = input_message[input_count];

      command_check = dic_cat_command (bookmark_command, input_message[input_count]);

      if (command_check == 2)//help
        {
          command = input_message[input_count];
          dic_error_exit (command);
        }
      else if (command_check == 3)//add
        {
          command = input_message[input_count];
          in_word = input_message[input_count + 1];
        }
      else if (command_check == 4)//search remove
        {
          command = input_message[input_count];
          in_word = input_message[input_count + 1];
        }
      else if (command_check == 5)// null error
        {
          command = NULL;
          in_word = NULL;
        }

      if (s_exist == 0)
        {
          path_command = (char *) malloc (sizeof (char) * strlen (argv[0] + 5));
          sprintf (path_command, "%s.dat", argv[0]);

          fp = fopen (path_command, "r");

          if (fp == NULL)
            {
              path_command = "dic.dat";//data file 은 내위치 에 없으면 , 실행 파일 위치에서 해야한다 [argv[0]]
              fp = fopen (path_command, "r");

              if (fp == NULL)
                {
                  printf ("Could not read the file\n");
                  exit (EXIT_FAILURE);
                }
            }

          if (in_word == NULL)
            dic_error_exit (bookmark_command);
          return_search = dic_search_check (path_command, in_word, bookmark_command);//존재여부 line43
        }
      else if (s_exist == 1)
        {
          int path_len;
          int s;
          int path_num;
          int dat_check;
          char check_dat[3] = "dat";
          char check_path[4];

          path_num = 0;
          dat_check = 0;

          path_command = s_path;
          path_len = strlen (path_command);

          for (s = path_len - 3; s <= path_len; s++)
            {
              check_path[path_num] = path_command[s];
              path_num++;
            }
          check_path[path_num] = '\n';

          if (!strcmp (check_dat, check_path))
            {
              dat_check = 1;
            }

          if (dat_check == 1)
            {
              fp = fopen (path_command, "r");

              if (fp == NULL)
                {
                  printf ("Could not write the file\n");
                  exit (EXIT_FAILURE);
                }
            }

          if (in_word == NULL)
            dic_error_exit (bookmark_command);
          return_search = dic_search_check (path_command, in_word, bookmark_command);//존재여부 line43
        }
    }

  if (!strcmp (command, DIC_COMMAND_LIST))
    {
      print_tree (root, fp, bookmark_command);
      return 1;
    }
  else if (!strcmp (command, DIC_COMMAND_SEARCH))
    {
      if (return_search >= 0)
        {
          if (server_exist == 1)
            {
              char *write_message;
              int wri_len;

              wri_len = strlen (in_word) + strlen (dic_save_data -> explain);
              write_message = (char *) realloc (NULL, sizeof (char) * wri_len + 2);
              memset (write_message, 0, wri_len + 2);

              strcat (write_message, in_word);
              strcat (write_message, "|");
              strcat (write_message, dic_save_data -> explain);
              write_message[wri_len + 1] = '\n';

              write (clnt_sock, write_message, (wri_len + 2));
            }
          else if (server_exist == 0)
            {
              printf ("%s\n", in_word);
              printf ("%s\n", dic_save_data -> explain);
            }
        }
      else
        {
          printf ("is a word thae does not exist : %s\n", in_word);
        }
    }
  else if (!strcmp (command, DIC_COMMAND_ADD))
    {
      if (return_search >= 0)
        {
          fclose (fp);
          printf ("Are registered in advance : %s\n", in_word);
        }

      if (bookmark_value == 0)
        {
          if (server_exist == 0)
            {
              char *in_explan;

              if (input_message[input_count + 2] == NULL)
                dic_error_exit (bookmark_command);

              in_explan = (char *) malloc (sizeof (char) * (strlen (input_message[input_count + 2]) + 2));
              strcpy (in_explan, (input_message[input_count + 2]));
              dic_add (in_word, path_command, in_explan);
            }
          else if (server_exist == 1)
            {
              fclose (fp);
              dic_add (in_word, path_command, serv_in_explan);
            }
        }
      else if (bookmark_value == 1)
        {
          dic_add (in_word, path_command, NULL);
        }
    }
  else if (!strcmp (command, DIC_COMMAND_REMOVE))
    {
      if (return_search >= 0)
        {
          if (bookmark_value == 1)
            {
              dic_book_remove (root, in_word);
              remove ("list.dat");
              rename ("save.txt", "list.dat");
            }
          else if (bookmark_value == 0)
            {
              dic_scan (path_command, in_word, bookmark_command);
              print_tree (root, fp, bookmark_command);
              remove ("dic.dat");
              rename ("dic.test", "dic.dat");
            }
        }
      else
        printf ("is a word that does not exist : %s\n", in_word);
    }
  else if (!strcmp (command, DIC_COMMAND_HELP))
    {
      dic_error_exit (bookmark_command);
    }
  /**
   * check_list == 1이라면 list.txt 값을 출력한다.
   * book_command 값이 add 라면 list_txt값에 저장한다.
   * book_command 값이 remove 라면 list_txt값에서 삭제한다.
   * book_command 값이 help 라면 msg 를 출력한다.
   */
  /**
   * bookmark 옵션이 없는 경우
   * b_exist 가 존재하면 안된다.
   * -s 옵션이 없는 s_exist = 0
   * -s 옵션이 있는 s_exist = 1
   *  command option
   *  add, search, remove
   */
  close (clnt_sock);

  return 0;
}
