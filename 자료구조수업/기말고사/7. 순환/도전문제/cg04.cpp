/*
다음의 수식과 같이 순환적으로 표현되는 Ackermann 함수를 구현하고 테스트한다
a(0, n)=1
a(1, 0)=2
a(m, 0)=m+2, if m>1
a(m, n)=a(a(m-1), n), n-1), if m>0 and n>0
*/

#include <iostream>

using namespace std;

int Ackermann(int m, int n)
{
    if (m == 0)
        return 1;
    else if (m == 1 && n == 0)
        return 2;
    else if (n == 0)
        return m + 2;
    else
       return Ackermann(Ackermann(m - 1, n), n - 1);
}

int main(void)
{
    cout << "Ackermann(0, 3) = " << Ackermann(0, 3) << endl;
    cout << "Ackermann(1, 0) = " << Ackermann(1, 0) << endl;
    cout << "Ackermann(3, 0) = " << Ackermann(3, 0) << endl;
    cout << "Ackermann(4, 2) = " << Ackermann(4, 2) << endl;
    return 0;
}