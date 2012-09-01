#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  char usage [] = "usage: trash <-d> filename\n";
  int ret = 0;
  char newfilename [256] = "";

  if (argc <= 1) {
    printf ("%s", usage);
    return 1;
  }

  else if (strcmp (argv[1], "-d") == 0) {
    if (argc <= 2) {
      printf ("%s", usage);
      return 2;
    }
    ret = remove (argv[2]);
    if (ret == 0)
      printf ("파일을 삭제했습니다.\n");
    else
      printf ("파일을 삭제할 수 없습니다.\n");
  }

  else {
    sprintf (newfilename, "%s.bak", argv[1]);
    ret = rename (argv[1], newfilename);

    if (ret == 0)
      printf ("파일명의 끝에 .bak를 추가합니다.\n");
    else
      printf ("파일명을 바꿀 수 없습니다.\n");
  }

  return 0;
}
