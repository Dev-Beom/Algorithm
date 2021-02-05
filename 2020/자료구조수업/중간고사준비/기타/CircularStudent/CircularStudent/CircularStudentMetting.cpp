#include "CircularStudent.h"

int main(void)
{
    CircularStudent male, female; //남자 여자
    char name[20];
    char gender; //성별
    cout << "미팅 주선 프로그램입니다" << endl;
    cout << "프로그램 종료 원하시면 이름에 '그만'을 입력해주세요" << endl
         << endl;
    while (1)
    {
        cout << "고객이름: ";
        cin >> name;
        if (!strcmp(name, "그만"))
            break;
        cout << "성별을 입력하세요(f or m) ";
        cin >> gender;
        if (gender == 'm')
            male.enqueue(name);
        else if (gender == 'f')
            female.enqueue(name);

        if (!male.isEmpty() && !female.isEmpty()) //여자 남자 한쌍을 이룰 경우
        {
            char boyfriend[20], girlfriend[20];
            strcpy(boyfriend, male.dequeue());
            strcpy(girlfriend, female.dequeue());

            cout << "커플이 탄생했습니다! " << boyfriend << "와 " << girlfriend << endl
                 << endl;
        }
        else
            cout << "아직 대상자가 없습니다. 기다려주십시요." << endl
                 << endl;
    }
    return 0;
}