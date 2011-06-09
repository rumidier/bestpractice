#include <stdio.h>

#define STR_LEN         50
#define BOOK_INFO_NUM   3

char
book_title[BOOK_INFO_NUM][STR_LEN];

char
book_pub[BOOK_INFO_NUM][STR_LEN];

int
book_price[BOOK_INFO_NUM];

int
main (int   argc,
      char *argv[])
{
  int i;

  puts ("**************** 도서 정보 입력 ****************");

  for (i = 0; i < BOOK_INFO_NUM; i++)
    {
      printf ("%d번째 도서 정보 입력. \n", (i + 1));

      fputs ("도서 제목 : ", stdout);
      gets (book_title[i]);

      fputs ("출판사 명 : ", stdout);
      gets (book_pub[i]);

      fputs ("도서 가격 : ", stdout);
      scanf ("%d", &book_price[i]);
      getchar ();

      printf ("%d번째 입력 완료...............\n\n", (i + 1));
    }

  puts ("**************** 도서 정보 입력 ****************");
  for (i = 0; i < BOOK_INFO_NUM; i++)
    {
      printf ("%d번째 도서 정보 출력. \n", (i + 1));
      printf ("도서 제목 : %s \n", book_title[i]);
      printf ("출판사 명 : %s \n", book_pub[i]);
      printf ("도서 가격 : %d \n\n", book_price[i]);
    }

  return 0;
}
