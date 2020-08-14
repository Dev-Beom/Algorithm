/*
문제: https://www.acmicpc.net/problem/2231

Input: 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

Output: 첫째 줄에 답을 출력한다. 생성자가 없는 경우에는 0을 출력한다.
*/

#include <iostream>

using namespace std;

int calc(int input)
{//연산 함수
    int arr[7];
    int tmp = input;
    int sum = 0;
    int result = input;

    for (int i = 0; i < input; i++)
    {
        tmp--;
        arr[0] = tmp / 1000000;            //백만의 자리수
        arr[1] = (tmp % 1000000) / 100000; //십만의 자리수
        arr[2] = (tmp % 100000) / 10000;   //만의 자리수
        arr[3] = (tmp % 10000) / 1000;     //천의 자리수
        arr[4] = (tmp % 1000) / 100;       //백의 자리수
        arr[5] = (tmp % 100) / 10;         //십의 자리수
        arr[6] = (tmp % 10);               //일의 자리수
        for (int j = 0; j < 7; j++) //분해합 구하기
        {
            sum = sum + arr[j];
        }
        sum = sum + tmp;
        if (sum == input && result > tmp)   //가장 작은 생성자 나열
        {
            result = tmp;
        }
        sum = 0;
    }
    if (result == input)    //예외처리
    {
        cout << 0 << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int input;

    cin >> input;

    calc(input);

    return 0;
}