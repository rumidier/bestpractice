#include <stdio.h>
#include <stdlib.h>

#define STR_LEN           50
#define BOOK_INFO_LEN     3

typedef struct _BookInfo {
  char book_title[STR_LEN];
  char book_pub[STR_LEN];
  int book_price;
} BookInfo;

BookInfo
book_list[BOOK_INFO_LEN];

int
main (int   argc,
      char *argv[])
{
  int i;

  puts ("**************** 도서 정보 입력 ****************");

  for (i = 0; i < BOOK_INFO_LEN; i++)
    {
      printf ("%d번째 도서 정보 입력. \n", (i + 1));

      fputs ("도서 제목 : ", stdout);
      gets (book_list[i].book_title);

      fputs ("출판사 명 : ", stdout);
      gets (book_list[i].book_pub);

      fputs ("도서 가격 : ", stdout);
      scanf ("%d", &book_list[i].book_price);
      getchar ();

      printf ("%d번째 입력 완료...............\n\n", (i + 1));
    }

  puts ("**************** 도서 정보 입력 ****************");
  for (i = 0; i < BOOK_INFO_LEN; i++)
    {
      printf ("%d번째 도서 정보 출력. \n", (i + 1));
      printf ("도서 제목 : %s \n", book_list[i].book_title);
      printf ("출판사 명 : %s \n", book_list[i].book_pub);
      printf ("도서 가격 : %d \n\n", book_list[i].book_price);
    }

  return 0;

}
