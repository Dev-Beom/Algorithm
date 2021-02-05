#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
// #include "Customer.h"

class LinkedQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedQueue() : front(NULL), rear(NULL){};
    ~LinkedQueue()
    {
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(Node *p)
    {
        if (isEmpty())
        {
            front = rear = p;
        }
        else
        {
            rear->setLink(p);
            rear = p;
        }
    }

    Node *dequeue()
    {
        Node *p = front;

        if (front == rear && !isEmpty())
        {
            front = rear = NULL;
        }
        else if (front != rear)
        {
            front = p->getLink();
        }
        return p;
    }

    Node *peek()
    {
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            return front;
        }
    }
};