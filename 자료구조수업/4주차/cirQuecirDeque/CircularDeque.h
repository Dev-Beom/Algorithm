
#include "CircularQueue.h"

class CircularDeque : public CircularQueue
{
public:
    CircularDeque() {}
    void addRear(int val) { enqueue(val); }
    int deleteFront() { return dequeue(); }
    int getFront() { return peek(); }

    void display()
    {
        printf("덱의 내용: ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
        {
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        }
        printf("\n");
    }

    int getRear()
    {
        if (isEmpty())
        {
            printf("Error: 덱이 공백상태입니다.\n");
        }
        else
        {
            return data[rear];
        }
    }

    void addFront(int val)
    {
        if (isFull())
        {
            printf("Error: 덱이 포화상태입니다.\n");
        }
        else
        {
            data[front] = val;
            front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }

    int deleteRear()
    {
        if (isEmpty())
        {
            printf("Error: 덱이 공백상태입니다.\n");
        }
        else
        {
            int ret = data[rear];
            rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
};