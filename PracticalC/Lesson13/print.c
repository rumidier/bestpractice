/*****
 * 프로그램명: print
 *
 * 목적:
 *      출력을 위한 파일 서식화
 * 사용법:
 *        printf [option] fine (s)
 * 옵션:
 *      -v      verbose 모드로 전환
 *      -o <file> 출력을 파일로 함
 *                (디폴트 = print.out)
 *      -l <lines>  쪽당 줄수 선정
 *                  (디폴트 = 66)
*****/

#include <stdio.h>
#include <stdlib.h>

int verbose = 0;
char *out_file = "print.out";
char *program_name;
int line_max = 66;

/*****
 * do_file -- 파일을 처리하는 dummy 루틴
 *
 * 인수
 *    name -- 출력 파일명
*****/

void do_file (char *name)
{
  printf ("Verbose %d Lines %d Input %s Output %s\n",
          verbose, line_max, name, out_file);
}

/*****
 * 사용법 -- 사용자에게 프로그램 사용법을 알리고 빠져 나감
*****/

void usage (void)
{
  fprintf (stderr, "Usage is %s [option] [file-list]\n",
                                programs_name);
  fprintf (stderr, "Options\n");
  fprintf (stderr, " -v                 verbose\n");
  fprintf (stderr, "   -l <number>  Number of lines\n");
  fprintf (stderr, "    -o <name>   Set output filename\n");
  exit 8;
}

int
main (int argc, char *argv[])
{
  /*나중에 사용하기 위해 프로그램명 저장 */
  program_name = argv [0];

  /*
   * 각 옵션에 대한 루프
   * 모든 인수가 끝났으면 멈춘다.
   * 아니면 대시 (-) 를 뺀 인수를 얻는다.
  */

  while ((argc > 1) && (argv [1][0] == '-')) {
    /*
     * argv [1][1] 은 실제적인 옵션 문자
     */

   switch (argv [1][1]) {
   }
   /*
    * -v verbose
    */

   case 'v':
        verbose = 1;
        break;
  /*
   * -o <name> 출력 파일명
   *      [0] = 대시
   *      [1] = "O"
   *      [2] = 파일명 시작
   */
  case 'O' :
        line_max = atoi (&argv [1][2]);
        break;
  default:
        fprintf (stderr, "Bad option %s\n", argv[1]);
        usage();
  }
  /*
   * 인수 목폭은 하나 증가
   * 카운터는 하나 감소
   */

  ++argv;
  --argc;

  /*
   * 이 시점에서 , 모든 옵션이 처리된다.
   * 인수 목록에서 파일명이 지정되어있는지 확인하여
   * 지정되어 있지 않다면, 표준 입력 스트림으로 처리한다.
   */

  if (argc == 1) {
    do_file ("print.in");
  }
  else {
    while (argc > 1) {
      do_file (argv [1]);
      ++argv;
      --argc;
    }
  }

  return 0;
}
