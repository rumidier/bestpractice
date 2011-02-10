#include <stdio.h>
#include <string.h>



char Help_Input[50]; // 도움말 호출 변수

char Choice;  // 물음을 위한 변수

int i = 0; // 반복 횟수 설정 변수



int Program_Intro(void); // 프로그램 소개

void Program_Helper(void); // 프로그램 도움말

void Part_1_1(void); // Part 1-1

void Part_1_2(void); // Part 1-2

void Part_2_1(void); // Part 2-1

void Part_3_1(void); // Part 3-1

void Part_4_1(void); // Part 4-1





int main(void)

{

  int Input;



first:

  printf("※ 필독 사항 : 이책은 각 파트의 관련 문제를 모아서 분기시켜 놓은 프로그램입니다.");

  printf("각 문제를 풀고 답을 네이트온 쪽지로 보내주세요 그럼 그다음 문제를 풀기위해 비밀번호를 알려드립니다. 어렵진 않지만 도전하셔서 문제 꼭 푸시길바랍니다\n");

  printf("제 네이트온 메일은 dbenrdl@nate.com 입니다.\n\n");

  printf("*************************************\n");

  printf("1. Part 01 C언어의 기본.\n");

  printf("2. Part 02 포인터와 배열의 시작.\n");

  printf("3. Part 03 포인터와 배열의 완성(공사중).\n");

  printf("4. Part 04 C언어의 깊은 이해.(공사중)\n");

  printf("5. Program Intro.\n");

  printf("*************************************\n\n");



  printf("Choice : ");

  scanf("%d", &Input);



  switch(Input)

    {

    case 1:

      printf("Part One 에 오신걸 환영합니다. C언어의 기본이니 쉬우실 껍니다. 그럼 화이팅 !!!\n");

      Part_1_1();

      break;



    case 2:

      printf ("Part Two 에 오신걸 환영합니다. 포인터와 배열을 한번 알아봅시다. 도전 !!!\n");

      //Part_two();

      break;



    case 3:

      printf("************************************************\n아직 공사중입니다. 다른 Part 를 이용해주세요.\n************************************************\n\n");

      main();

      break;



    case 4:

      printf("************************************************\n아직 공사중입니다. 다른 Part 를 이용해주세요.\n************************************************\n\n");

      main();

      break;



    case 5:

      printf("프로그램 도움말 에 오신걸 환영합니다. 여기서 자세한 설명을 들으실수 있습니다.\n\n");

      Program_Intro();

      break;



    default:

      printf("잘못 입력 하셨습니다. 처음으로 Warp 합니다.\n");

      goto first; // 처음 써보는 goto 문 ㅎ_ ㅎ

    }

  return 0;
}



int Program_Intro(void)

{

  printf("1. 안녕하세요 Silent Assassin 입니다. 이 프로그램을 만들게 된 계기는 저도 공부하고 사용하시는 분들도 공부 하는 차원에서 만들게되었습니다.\n\n");

  printf("2. CMS Program 0.1v은 윤성우님의 열혈 C 개정판을 응용하여 문제를 냈습니다. 문제를 푸시고 네이트온으로 답을 보내주시면 비밀번호를 드리겠습니다.\n\n");

  printf("3. CMS Program 0.1v은 아직 미완성 입니다 Part 3,4 는 소스코드를 다 작성하면 추후 버전업을 하고 추가 되겠습니다 이점 죄송합니다.\n\n");

  printf("4. 저도 실력이 턱없이 부족하지만 프로그램 잘 사용해주시면 정말로 감사 드리겠습니다.\n\n");

  printf("5. 이 프로그램의 저작권은 닉네임 Silent Assassin 에게 있습니다.\n\n");

  printf("6. Help : 명령어보기 Help 입력시 도움말을 호출합니다 (파트에서만 적용됩니다)\n\n");



  fflush(stdin); // 저장된 버퍼 비우기



  printf("처음으로 돌아 가시겠습니까?(Y/N) : ");

  scanf("%c", &Choice);



  switch(Choice)

    {

    case 'y':

    case 'Y':

      main();



    case 'n':

    case 'N':

      return -1;

    }

  return 0;
}



void Program_Helper(void)

{

  printf("***************************************************************************\n");

  printf("Warp : 메인으로 이동 , Giveup : 포기 , Hint : 힌트 , Password : 패스워드 입력.\n");

  printf("※ 주의 사항 : 단어 입력시 스펠링이 틀리면 프로그램이 비정상적으로 종료됩니다. ※\n");

  printf("***************************************************************************\n");

}



void Part_1_1(void)

{

  const int PASSWORD = 0x00f21265;

  int PASSWORD_input; // 비밀번호 입력



  printf("***************************************************************************\n1번 문제입니다. 서식문자를 사용 하여 다음 문제의 소스코드를 작성하여라.\n");

  printf("***************************************************************************\n\n");

  printf("Name : %s %s \n", "Silent", "Assassin");

  printf("Age : %d \n", 20);

  printf("Address : %d - %d \n", 444, 555);

  printf("Phone Number : %d - %d - %d \n\n", 123, 1234, 1234);



Part_1_1_1:  // 1_1_1 처음 위치 재설정 Part 1 1번문제 위치 1

  printf("INPUT : ");

  scanf("%s", Help_Input);

  if(!strcmp (Help_Input ,"Help"))

    {

      Program_Helper();

    }

  else if(!strcmp (Help_Input, "Warp"))

    {

      main();

    }

  else if(!strcmp (Help_Input, "Giveup"))

    {

      printf("포기 하시겠습니까?(Y/N) : ");

      scanf("%c", &Choice);

      switch(Choice)

        {

        case 'y':

        case 'Y':

          main();



        case 'n':

        case 'N':

          goto Part_1_1_1;

        }

    }

  else if(!strcmp (Help_Input, "Hint"))

    {

      printf("************************************************\nHint : 문자열 출력은 \"문자열\" 로 표현합니다.\n************************************************\n\n");

      goto Part_1_1_1;

    }

  else if(!strcmp (Help_Input, "Password"))

    {

      while(i<1)

        {

          printf("PASSWORD : ");

          scanf("%d", &PASSWORD_input);

          if(PASSWORD_input == PASSWORD)        // 15864421 입력시 암호 일치 조건문 내용 실행

            {

              printf("***************\n암호 일치.\n***************\n\n");

              printf("다음으로 넘어 가시겠습니까?(Y/N) : ");

              scanf("%c", &Choice);

              switch(Choice)

                {

                case 'y':

                case 'Y':

                  Part_1_2();



                case 'n':

                case 'N':

                  goto Part_1_1_1;

                }

            }

          i++; // 횟수 증가 암호 입력횟수는 1회

        }

    }

  else

    {

      printf("※알수 없는 명령어 입니다.※\n\n");

      goto Part_1_1_1;

    }

}



void Part_1_2(void)

{

  printf("공사\n");

  main();

}
