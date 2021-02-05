/*
다음을 계산하는 순환적인 프로그램을 작성하라
1+2+3+...+n
*/

#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 1)
        return 1;
    else
       return n + sum(n - 1);
}

int main(void)
{
    int num;
    cout << "n값 입력: ";
    cin >> num;
    cout << "1부터 " << num << "까지 더한 결과: " << sum(num) << endl;
    return 0;
}
