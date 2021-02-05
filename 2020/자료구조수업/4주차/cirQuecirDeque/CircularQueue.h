#pragma once

#define MAX_QUEUE_SIZE 100
#include "stdio.h"

class CircularQueue
{
protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

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

    void enqueue(int val)
    {
        if (isFull())
        {
            printf("Error: 큐가 포화상태입니다.\n");
        }
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            printf("Error: 큐가 공백상태입니다.\n");
        }
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            printf("Error: 큐가 공백상태입니다.\n");
        }
        else
        {
            return data[(front + 1) % MAX_QUEUE_SIZE];
        }
    }

    void display()
    {
        printf("큐 내용: ");
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
        {
            printf("[%2d] ", data[i % MAX_QUEUE_SIZE]);
        }
        printf("\n");
    }
};