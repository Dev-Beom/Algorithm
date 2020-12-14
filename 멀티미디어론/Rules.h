#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Rules
{
private:
    string interests;
    string personality;
    bool isReal;
    string recommendation;

public:
    Rules();
    ~Rules();
    string inputInterest(string inputString);
    string inputHobby(string inputString);
    string inputIsReal(string inputString);

    string calcRecommendation();

    void inputFunction();

};

Rules::Rules()
{
}

Rules::~Rules()
{
}

string Rules::inputInterest(string inputString)
{
    if (inputString == "컴퓨터" || inputString == "기계" || inputString == "물리" || inputString == "전자전기")
    {
        interests = "공학계통";
    }
    else if (inputString == "경영" || inputString == "경제" || inputString == "회계" || inputString == "세무")
    {
        interests = "상경계통";
    }
    else if (inputString == "디자인" || inputString == "무용/체육" || inputString == "음악" || inputString == "연극/영화")
    {
        interests = "예체능계통";
    }
    else if (inputString == "문학" || inputString == "어학" || inputString == "종교" || inputString == "심리")
    {
        interests = "인문계통";
    }
    else
    {
        interests = "NULL";
    }
    return interests;
}

string Rules::inputHobby(string inputString)
{
    if (inputString == "강의하는" || inputString == "조언하는" || inputString == "상담하는")
    {
        personality = "언어적";
    }
    else if (inputString == "만드는" || inputString == "수리하는" || inputString == "조정하는")
    {
        personality = "실무적";
    }
    else if (inputString == "그리는" || inputString == "움직이는" || inputString == "듣는")
    {
        personality = "활동적";
    }
    else if (inputString == "평가하는" || inputString == "추론하는" || inputString == "조사하는")
    {
        personality = "분석적";
    }
    else
    {
        personality = "NULL";
    }
    return personality;
}

string Rules::inputIsReal(string inputString)
{
    if (inputString == "있다")
        isReal = true;
    else if (inputString == "없다")
        isReal = false;
    else
        isReal = NULL;

    return inputString;
}

string Rules::calcRecommendation()
{
    if (interests == "공학계통" && personality == "실무적" && isReal == true)
    {
        recommendation = "컴퓨터공학";
    }
    else if (interests == "상경계통" && personality == "분석적" && isReal == false)
    {
        recommendation = "경영";
    }
    else if (interests == "인문계통" && personality == "언어적" && isReal == false)
    {
        recommendation = "언어";
    }
    else if (interests == "예체능계통" && personality == "활동적" && isReal == false)
    {
        recommendation = "무용/체육";
    }
    else if (interests == "인문계통" && personality == "분석적" && isReal == false)
    {
        recommendation = "심리";
    }
    else if (interests == "예체능계통" && personality == "실무적" && isReal == true)
    {
        recommendation = "디자인";
    }
    else
    {
        recommendation = "NULL";
    }
    return recommendation;
}

void Rules::inputFunction()
{
    cout << "전공을 추천해주는 전문가 시스템입니다. for C++\n\n관심분야 list -> [컴퓨터, 물리, 기계, 전자전기, 경영, 경제, 회계, 세무, 디자인, 무용/체육, 음악, 연극/영화, 문학, 어학, 종교, 심리] 중 택 1\n>> ";
    string inputString;
    cin >> inputString;
    cout << inputInterest(inputString) << "입니다.\n\n취미 list -> [강의하는, 조언하는, 상담하는, 만드는, 수리하는, 조정하는, 그리는, 움직이는, 듣는, 평가하는, 추론하는, 조사하는] 중 택 1\n>> " << endl;
    cin >> inputString;
    cout << inputHobby(inputString) << "입니다.\n\n실물 list -> [있다, 없다] 중 택 1\n>> " << endl;
    cin >> inputString;
    cout << inputIsReal(inputString) << "입니다.\n\n"
         << endl;
    cout << calcRecommendation() << "분야를 추천합니다." << endl;
}