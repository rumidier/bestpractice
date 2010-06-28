/********************
 * input = st1, st2, st3
 * save = first_score, snd_score
 * compare the input and storage
 * "A" first and snd
*********************/

#include <stdio.h>

int
main (int argc, char *argv[])
{
  int st1, st2, st3;
  int first_score;
  int snd_score;

  first_score = 0;
  snd_score = 0;

  printf ("점수 입력 : ");
  scanf ("%d", &st1);

  if (st1 >= first_score)
    {
      snd_score = first_score;
      first_score = st1;
    }
  else if (st1 < first_score && st1 > snd_score)
    {
      snd_score = st1;
    }//first와snd 의 점수를 저장 관리 한다.

  printf ("점수 입력 : ");
  scanf ("%d", &st2);

  if (st2 >= first_score)
    {
      snd_score = first_score;
      first_score = st2;
    }
  else if (st2 < first_score && st2 > snd_score)
    {
      snd_score = st2;
    }

  printf ("점수 입력 : ");
  scanf ("%d", &st3);

  if (st3 >= first_score)
    {
      snd_score = first_score;
      first_score = st3;
    }
  else if (st3 < first_score && st3 > snd_score)
    {
      snd_score = st3;
    }

  printf ("A 학점은 %d점 이상이 되어야 합니다.\n", snd_score);

  return 0;
}
