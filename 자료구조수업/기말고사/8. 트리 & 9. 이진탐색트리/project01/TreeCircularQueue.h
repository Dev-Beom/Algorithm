/*
레벨 순회 프로그램
*/

#include "BinaryNode.h"

#include <iostream>

using namespace std;

inline void error(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

#define MAX_QUEUE_SIZE 100

class CircularQueue
{
    int front;
    int rear;
    BinaryNode *data[MAX_QUEUE_SIZE];

public:
    CircularQueue()
    {
        front = rear = 0;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }

    void enqueue(BinaryNode *n)
    {
        if (isFull())
            error("Error:큐가 포화상태입니다\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = n;
        }
    }

    BinaryNode *dequeue()
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};