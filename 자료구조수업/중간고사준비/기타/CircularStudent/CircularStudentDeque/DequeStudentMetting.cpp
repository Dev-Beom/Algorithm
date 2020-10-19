#include "CircularStudentDeque.h"
 
int main(void)
{
        CircularStudentDeque male, female; //남자 여자
        char answer; //답변
        char gender; //성별
        char name[20];
        cout << "미팅 주선 프로그램입니다" << endl;
        cout << "프로그램 종료 원하시면 이름에 'stop'을 입력해주세요" << endl << endl;
        while (1)
        {
               cout << "고객이름: ";
               cin >> name;
               if (!strcmp(name, "그만"))
                       break;
               cout << "성별을 입력하세요(f or m) ";
               cin >> gender;
               cout << "주선을 즉시 원하십니까?";
               cin >> answer;
               if (gender == 'm' && answer == 'y')
                       male.addFront(name);
               else if (answer == 'n')
                       male.addRear(name);
               else if (gender == 'f' && answer == 'y')
                       female.addFront(name);
               else if (answer == 'n')
                       female.addRear(name);
 
               if (!male.isEmpty() && !female.isEmpty()) //여자 남자 한쌍을 이룰 경우
               {
                       char boyfriend[20], girlfriend[20];
                       strcpy(boyfriend, male.deleteFront());
                       strcpy(girlfriend, female.deleteFront());
 
                       cout << "커플이 탄생했습니다! " << boyfriend << "와 " << girlfriend << endl << endl;
               }
               else
                       cout << "아직 대상자가 없습니다. 기다려주십시요." << endl << endl;
        }
        return 0;
}