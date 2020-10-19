#include "CircularIntQueue.h"
#include <ctime>

class CircularSimulator
{
private:
    int maxStudent;     //참여한 총 인원 수
    double perticipate; //단위시간에 등록하는 학생 수
    int couple;         //미팅 주선에 성공한 커플의 쌍의 번호
    int count;          //학생 번호
    int student;        //참여한 학생 수
    double probArrival; //단위시간 당 미팅에 나오는 평균 학생 수
    int m;
    int f;
    int random; //성별 무작위
    CircularIntQueue que;

    //랜덤 숫자를 생성하여 고객 도착 여부와 서비스 시간 자동 생성 코드
    double Random()
    {
        return rand() / (double)RAND_MAX;
    }
    bool IsNewStudent()
    {
        return (Random() > probArrival);
    }

public:
    CircularSimulator()
    {
        count = couple = m = f = student = 0;
    }
    void readSimulationParameters()
    {
        cout << "시뮬레이션 할 최대 인원(예:100) = ";
        cin >> maxStudent;
        cout << "단위시간에 나오는 학생 수(예:0.5) = ";
        cin >> probArrival;
    }
    void run()
    {
        CircularIntQueue male, female; //남학생 여학생
        while (count < maxStudent)
        {
            cout << count + 1 << "번째 시도" << endl;
            if (IsNewStudent())
            {
                student++;
                random = rand() % 2;
                if (!random)
                {
                    male.enqueue(count);
                    m++;
                    cout << "남학생이 참석했습니다" << endl;
                }
                else
                {
                    female.enqueue(count);
                    f++;
                    cout << "여학생이 참석했습니다" << endl;
                }
            }
            else
            {
                cout << "아쉽게도 " << count << " 학생은 바빠서 참석하지 못했습니다" << endl;
            }

            if (!male.isEmpty() && !female.isEmpty())
            {
                int boyfriend, girlfriend;
                boyfriend = male.dequeue();
                girlfriend = female.dequeue();
                cout << "미팅 성공! " << boyfriend << "와" << girlfriend << "가 커플이 되었습니다" << endl
                     << endl;
                couple++;
            }
            else
                cout << "아직 대상자가 없습니다. 기다려주십시오" << endl
                     << endl;
            count++;
        }
    }
    void printStat()
    {
        cout << "=================================================================" << endl;
        cout << "미팅에 지원한 총 학생 수= " << maxStudent << endl;
        cout << "미팅에 참여한 학생 수= " << student << endl;
        cout << "성비(남학생:여학생) = " << m << " : " << f << endl;
        cout << "성사된 커플 수= " << couple << endl;
        cout << "안타까운 솔로들= " << maxStudent - 2 * (couple) << endl;
    }
};