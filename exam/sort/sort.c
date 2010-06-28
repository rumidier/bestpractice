#include <stdio.h>
#include <stdlib.h>

int
main (int    argc,
      char **argv)
{
  int i;
  int count;
  int *nums;

  if (argc < 2)
    {
      printf ("Usage: %s <num1> [<num2> <num3> ...]\n", argv[0]);
      exit (EXIT_FAILURE);
    }

  /**
   * Set nums
   */
  count = argc - 1;
  nums = (int *) malloc (count * sizeof (int));
  for (i = 0; i < count; ++i)
    {
      nums[i] = atoi (argv[i + 1]);
    }

  /**
   * Do real sort!!
   */


  int *new_num;
  int *last_num;
  int counter;
  int mi_num;
  int next_count;

  new_num = (int *) malloc (count * sizeof (int));
  last_num = (int *) malloc (count * sizeof (int));
  mi_num = nums[0];
  counter = 0;
  next_count = 0;

    for (i = 0; i < count; i++)
      {
        if (mi_num >= nums[i])
          {
            mi_num = nums[i];
          }//mi_num 가장 작은 수일때만 실행되어 찾는다.
        else
          {
            continue;
          }
      }

    while (counter < count)
      {
        last_num[counter] = mi_num;

        for (i = 0; i < count; i++)
          {
            if (mi_num < nums[i])
              {
                new_num[next_count] = nums[i];
                next_count++;
              }
            else
              {
                continue;
              }
          }//mi_num보다 큰수만 찾는다.

        mi_num = new_num[0];
        for (i = 0; i < next_count; i++)
          {
            if (mi_num > new_num[i])
              {
                mi_num = new_num[i];
              }//mi_num 가장 작은 수일때만 실행되어 찾는다.
            else
              {
                continue;
              }
          }

        next_count = 0;
        counter++;
      }

    for (i = 0; i < count; i++)
      {
        printf ("last[%d] \n", last_num[i]);
      }

  return 0;
}
