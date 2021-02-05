//연결리스트로 큐를 구현하세요(5장_2 PPT 6-11페이지와 첨부된 C5 자료 참고)

/*
연결리스트로 스택을 구현하세요(5장_2 PPT 2-5페이지와 첨부된 C5 자료 참고)
*/
#include "LinkedQueue.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedQueue queue;
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(new Node(i));
    }
    queue.display();
    cout << endl;
    delete queue.dequeue();
    delete queue.dequeue();
    delete queue.dequeue();
    queue.display();
    return 0;
}

