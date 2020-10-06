#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    CircularQueue queue;


    int input;
    int num1;
    int num2;

    int sum;
    
    queue.enqueue(0);
    queue.enqueue(1);
    cin >> input;
    if (input == 0)
    {
        cout << input << endl;
    }
    else if (input == 1)
    {
        cout << input << endl;
    }
    else
    {
        for (int i = 0; i < input; i++)
        {
            num1 = queue.dequeue();
            num2 = queue.dequeue();
            sum = num1 + num2;
            queue.enqueue(num2);
            queue.enqueue(sum);
        }
        cout << input << ":" << queue.dequeue() << endl;
    }
    return 0;
}