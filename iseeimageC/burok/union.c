#include <stdio.h>

union _user {
  int usernum; /*사용자 번호*/
  char name[10];
} user;

int
main (int argc, char *argv[])
{
  int flag = 0;
  printf ("입력항목은 ? (0 = 사용자 번호, 1 = 이름) ");
  scanf ("%d", &flag);

  if (flag) {
    printf ("name ? ");
    scanf ("%s", user.name);
    printf ("이름이 %s이군요.\n", user.name);
  }

  else {
    printf ("사용자 번호 ?");
    scanf ("%d", & (user.usernum));
    printf ("사용자 번호는 %d 이군요.\n", user.usernum);
  }

  return 0;
}
