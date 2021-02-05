#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

inline void error(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
};

#define MAX_QUEUE_SIZE 100

class CustomerQueue
{
    int front;
    int rear;
    Customer data[MAX_QUEUE_SIZE];

public:
    CustomerQueue() { front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
    void enqueue(Customer &val)
    {
        if (isFull() == false)
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    Customer &dequeue()
    {
        if (isEmpty())
            error("공백 상태 에러");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};
