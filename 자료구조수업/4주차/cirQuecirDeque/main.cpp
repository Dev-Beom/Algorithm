// #include "CircularQueue.h"

// int main(int argc, char const *argv[])
// {
//     CircularQueue que;
//     for(int i = 1; i < 10; i ++)
//     {
//         que.enqueue(i);
//     }
//     que.display();
//     que.dequeue();
//     que.dequeue();
//     que.dequeue();
//     que.display();
//     return 0;
// }

#include "CircularDeque.h"

int main(int argc, char const *argv[])
{
    CircularDeque deq;
    for (int i = 1; i < 10; i++)
    {
        if (i % 2)
        {
            deq.addRear(i);
        }
        else
        {
            deq.addRear(i);
        }
    }
    deq.display();
    deq.deleteFront();
    deq.deleteRear();
    deq.deleteFront();
    deq.display();
    return 0;
}
