#include<stdio.h>
long long int Permutation(long long int n, long long int r);    /* n개 중 r개의 나열 방법*/
long long int Combination(long long int n, long long int r);    /* n개 중 r개의 선택 방법 */
long long int Factorial(long long int n);

int main(void)
{
  long long int n, r;
  printf("개수와 선택의 수 입력: ");
  scanf("%lld %lld", &n, &r);

  printf("%lld개 중 %lld개의 나열 방법: %lld \n", n, r, Permutation(n, r));
  printf("%lld개 중 %lld개의 선택 방법: %lld \n", n, r, Combination(n, r));
  return 0;
}

long long int Permutation(long long int n, long long int r)
{
  return Factorial(n)/Factorial(n-r);
}

long long int Combination(long long int n, long long int r)
{
  return Permutation(n, r)/Factorial(r);
}

long long int Factorial(long long int n)
{
  long long int facto=1;
  int i;
  for(i=1; i<=n; i++)
    facto*=i;

  return facto;
} 
