/*
문제: https://www.acmicpc.net/problem/7568

Input: 첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다. 단, 2 ≤ N ≤ 50, 10 ≤ x,y ≤ 200 이다.

Output: 여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.
*/

#include <iostream>

using namespace std;

class Person //  Person 객체
{
private:
    int weight;
    int height;
    int ranking;

public:
    Person()
    {
        weight = 0;
        height = 0;
        ranking = 0;
    }

    void setPersonInfo(int weight, int height)
    {
        this->weight = weight;
        this->height = height;
    }

    void setRanking(int ranking) { this->ranking = ranking; }
    int getWeight() { return weight; }
    int getHeight() { return height; }
    int getRanking() { return ranking; }
};

int calc(int length)
{
    int weight;
    int height;
    int rank = 1; //  Rank의 기준점.

    Person *parr = new Person[length]; //  입력값 만큼 Person 객체를 만듦.

    for (int i = 0; i < length; i++) //  객체속의 변수의 값을 설정.
    {
        cin >> weight;
        cin >> height;
        if (weight < 10 || weight > 200 || height < 10 || height > 200) //  문제에서 제시한 예외처리.
        {
            return 0;
        }
        parr[i].setPersonInfo(weight, height);
    }
    for (int i = 0; i < length; i++) //  모든 값을 비교할 수 있도록 index의 최대치를 length로 설정.
    {
        for (int j = 0; j < length; j++) //  모든 값을 비교할 수 있도록 index의 최대치를 length로 설정.
        {
            if (parr[i].getWeight() < parr[j].getWeight() && parr[i].getHeight() < parr[j].getHeight())
            //  문제에서 제시한 자신보다 '큰 덩치'의 기준. 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다. k = rank
            {
                rank++;
            }
        }
        parr[i].setRanking(rank); //  rank 만큼 parr[i]의 랭킹을 수정.
        rank = 0;                 //  새로운 index의 rank 집계를 위한 rank 초기화.
    }
    for (int i = 0; i < length; i++) //  Person parr[i] 객체들의 Ranking을 나열.
    {
        cout << parr[i].getRanking();
        if (i != length - 1)
        {
            cout << " "; //  문제에서 제시한 예외처리.
        }
    }
    delete[] parr;
    return 0;
}

int main(int argc, char *argv[])
{
    int input; //   length: 사람의 수.
    cin >> input;
    if (2 > input || input > 50) //  문제에서 제시한 예외처리.
    {
        return 0;
    }
    calc(input);

    return 0;
}
