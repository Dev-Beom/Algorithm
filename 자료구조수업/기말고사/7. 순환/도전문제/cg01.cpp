/*
순환적인 방법으로 피보나치 수열을 호출하였을 때 함수가 중복되어 호출되는 것을
확인할 수 있도록 각 함수의 매개변수별 호출 빈도를 측정해 출력하라
*/

#include <iostream>

using namespace std;

//순환적인 피보나치수열 계산 프로그램
int fibonacci(int *count, int n)
{
    count[n]++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
   return (fibonacci(count, n - 1) + fibonacci(count, n - 2));
}

int main(void)
{
    int num;
    cout << "몇번 째 피보나치 수열을 확인하고 싶으십니까 ?";
    cin >> num;

    int *count = new int[num + 1];

    for (int i = 0; i < num + 1; i++)
        count[i] = 0; //초기화

    cout << num << "번째 피보나치 수열 숫자: " << fibonacci(count, num) << endl;

    for (int i = num; i >= 0; i--)
        cout << "fibonnaci(" << i << ") = " << count[i] << "번" << endl;

    delete[] count; //동적할당한 메모리 반환

    return 0;
}
