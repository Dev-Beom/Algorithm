/*
다음을 계산하는 순환적인 프로그램을 작성하라
1+1/2+1/3+...+1/n
*/

#include <iostream>

using namespace std;

double sum(int n) //분수이므로
{
    if (n == 1)
        return 1;
    else
        return (1 / (double)n) + sum(n - 1);
}

int main(void)
{
    int num;
    cout << "n 값 입력: ";
    cin >> num;
    cout << "1부터 1/" << num << "까지의 합 결과: " << sum(num) << endl;
    return 0;
}