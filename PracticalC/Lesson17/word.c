/**
 * words -- 파일을 읽어서 단어들을 아스키 순으로 정렬하여 출력함
 *
 * 사용법
 *        words <file>
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node {
  struct node *left;
  struct node *right;
  char        *word;
};

static struct node *root = NULL;

/**
 * memory_error -- 에러를 출력하고 빠져 나감
 */

void memory_error (void)
{
  fprintf (stderr, "Error : Out of memory\n");
  exit (EXIT_FAILURE);
}

/**
 * save_string -- 힙에 문자열 저장
 *
 * 매개변수
 *        string -- 저장할 문자열
 *
 * 반환값
 *        문자열이 복사된 새로운 메모리 할당 영역의 포인터
 */

char *save_string (char *string)
{
  char *new_string;

  new_string = malloc ((unsigned) (strlen (string) + 1));

  if (new_string == NULL)
    memory_error ();

  strcpy (new_string, string);

  return (new_string);
}

/**
 * enter -- 트리에 단어 넣기
 *
 * 매개변수
 *    node -- 현재 노드
 *    word -- 넣을 단어
 */

void
enter (struct node **node,
            char         *word)
{
  int result;
  char *save_string();
  void memory_error();
  /**
   * 현재 노드가 널이면, 트리의 맨 밑이고
   * 다라서 새로운 노드를 만들어야 한다.
   */

  if ((*node) == NULL) {
    /* 새로운 노드에 대한 메모리 할당 */
    (*node) = malloc (sizeof (struct node));

    if ((*node) == NULL)
      memory_error ();

    /* 새로운 노드 초기화 */
    (*node) -> left = NULL;
    (*node) -> right = NULL;
    (*node) -> word = save_string (word);

  }


/* 단어가 어느 방향으로 가야 할지 결정함 */
  result = strcmp ((*node) -> word, word);

/* 현재 노드에 이미
 * 이 단어가 있다면
 * 진행도 불필요 하다
 */

  if (result == 0)
    return;
  /** 단어는 왼쪽 서브트리나 오른쪽 서브트리로 진행한다. */

  if (result < 0)
    enter ( &(*node) -> right, word);
  else
    enter ( &(*node) -> left, word);
}

/**
 * scan -- 파일에서 단어를 읽어 들림
 *
 * 매개변수
 *      name -- 읽어들일 파일
 */

void
scan (char *name)
{
  char word[100];
  int  index;
  int  ch;
  FILE *in_file;

  in_file = fopen (name, "r");

  if (in_file == NULL) {
    fprintf (stderr, "Error : Unable to open %s\n", name);
    exit (EXIT_FAILURE);
  }

  while (1) {
    /* 공백 문자들은 그냥 지나침 */
    while (1) {
      ch = fgetc (in_file);

      if (isalpha (ch) || (ch == EOF))
        break;
    }

    if (ch == EOF)
      break;

    word [0] = ch;

    for (index = 1; index < sizeof (word); ++index)
      {
        ch = fgetc (in_file);

        if (!isalpha (ch))
          break;
        word [index] = ch;
      }
    /* 끝에 널문자 삽입 */
    word[index] = '\0';

    enter (&root, word);
  }

  fclose (in_file);
}

/**
 * print_tree -- 트리 내 단어를 출력
 *
 * 매개변수
 *        top -- 출력할 트리의 루트
 */

void
print_tree (struct node *top)
{
  if (top == NULL)
    return;

  print_tree (top -> left);
  printf ("%s\n", top -> word);
  print_tree (top -> right);
}

int
main (int   argc,
      char *argv[])
{
  if (argc != 2)
    {
      fprintf (stderr, "Error:Wrong number of parameters\n");
      fprintf (stderr, "      on the command line\n");
      fprintf (stderr, "Usage is: \n");
      fprintf (stderr, "Error:Wrong number of parameters\n");
      fprintf (stderr, "      words 'file'\n");
      exit (EXIT_FAILURE);
    }

  scan (argv[1]);
  print_tree (root);

  return 0;
}
