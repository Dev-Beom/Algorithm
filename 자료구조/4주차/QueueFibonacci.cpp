#include <iostream>

#include "CircularQueue.h"

using namespace std;

int main(void)

{

    CircularQueue queue;

    int num;

    queue.enqueue(0); //F(0)=0

    queue.enqueue(1); //F(1)=1

    cout << "몇번째 피보나치 수열을 보고 싶으십니까 >";

    cin >> num;

    if (num == 0)

        cout << "찾으시는 " << num << "번째 피보나치 수열 숫자는 0 입니다" << endl;

    else if (num == 1)

        cout << "찾으시는 " << num << "번째 피보나치 수열 숫자는 1 입니다" << endl;

    else

    {

        for (int i = 0; i < num; i++)

        {

            int num1 = queue.dequeue(); //F(n-2)

            int num2 = queue.dequeue(); //F(n-1)

            int add = num1 + num2;

            queue.enqueue(num2); //F(n)=F(n-1)+F(n-2)

            queue.enqueue(add);
        }

        cout << "찾으시는 " << num << "번째 피보나치 수열 숫자는 " << queue.dequeue() << "입니다" << endl;
    }

    return 0;
}