#include<stdio.h>
int CalSingleInst(int deposit, int year);
int CalCompndInst(int deposit, int year);

int main(void)
{
  int dep;      /* 예치금액 */
  int yer;      /* 예치기간 */
  int sRet, cRet;

  do{
    printf("예치금액 입력(1 이상): ");
    scanf("%d", &dep);
  }while(dep<=0);

  do{
    printf("예치기간 입력(5년 이상): ");
    scanf("%d", &yer);
  }while(yer<5);

  sRet=CalSingleInst(dep, yer);
  cRet=CalCompndInst(dep, yer);

  printf("단리 적용시 원금+이자: %d \n", sRet);
  printf("복리 적용시 원금+이자: %d \n", cRet);

  if(sRet>cRet)
    printf("단리로 적용하시는게 이익입니다! \n");
  else if(sRet<cRet)
    printf("복리 적용이 이익입니다! \n");
  else
    printf("차이가 없습니다. 아무거나 가입하세요! \n");

  return 0;
}

int CalSingleInst(int deposit, int year)
{
  double rate=7.2/100.0;
  double inst=0;

  int i;
  for(i=0; i<year; i++)
    inst+=(deposit*rate);

  return (int)(deposit+inst);
}


int CalCompndInst(int deposit, int year)
{
  double rate=4.7/100.0;
  double inst=0;

  int i;
  for(i=0; i<year; i++)
    inst += (deposit+inst)*rate;

  return (int)(deposit+inst);
} 
