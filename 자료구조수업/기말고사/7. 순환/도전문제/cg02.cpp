/*
자료형이 long인 경우 가장 큰 피보나치 수를 구하라
*/

#include <iostream>

using namespace std;
 
long fibonacii(long n)
{
        if (n < 2)
        {
               return n;
        }
        else
        {
               long temp, current = 1, last = 0;
               for (long i = 2; i <= n; i++)
               {
                       temp = current;
                       current += last;
                       last = temp;
               }
               return current;
        }
}
 
int main(void)
{
        long n = 0, result;
        cout << "자료형이 long인 경우 가장 큰 피보나치 수를 구하기 위해 하나하나 출력해보겠습니다" << endl;
        do
        {
               result = fibonacii(n);
               cout << "fibonacci(" << n << ") = " << result << endl;
               n++;
        } while (result >= 0); //오버플로우가 발생하면 음수가 된다
        //결국 1836311903이 최대 숫자
        return 0;
}