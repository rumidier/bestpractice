#include<stdio.h>
int Permutation(int n, int r);    /* n개 중 r개의 나열 방법*/
int Combination(int n, int r);    /* n개 중 r개의 선택 방법 */
int Factorial(int n);

int main(void)
{
  int n, r;
  printf("개수와 선택의 수 입력: ");
  scanf("%d %d", &n, &r);

  printf("%d개 중 %d개의 나열 방법: %d \n", n, r, Permutation(n, r));
  printf("%d개 중 %d개의 선택 방법: %d \n", n, r, Combination(n, r));
  return 0;
}

int Permutation(int n, int r)
{
  return Factorial(n)/Factorial(n-r);
}

int Combination(int n, int r)
{
  return Permutation(n, r)/Factorial(r);
}

int Factorial(int n)
{
  int facto=1;
  int i;
  for(i=1; i<=n; i++)
    facto*=i;

  return facto;
} 
