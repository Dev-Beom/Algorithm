#pragma once
#include "Node.h"
#include <stdio.h>
#include <string.h>

class LinkedStack
{
    Node *top;

public:
    LinkedStack()
    {
        top = NULL;
    }

    ~LinkedStack()
    {
        while (!isEmpty())
        {
            delete pop();
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(Node *p)
    {
        if (isEmpty())
        {
            top = p;
        }
        else
        {
            p->setLink(top);
            top = p;
        }
    }

    Node *pop()
    {
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            Node *p;
            p = top;
            top = p->getLink();
            return p;
        }
    }

    Node *peek()
    {
        if (isEmpty())
        {
            return NULL;
        }
        else
        {
            return top;
        }
    }

    int size()
    {
        Node *p;
        int count = 0;
        for (Node *p = top; p != NULL; p = p->getLink())
        {
            count++;
        }
        return count;
    }

    // void display()
    // {
    //     for(Node *p = top; p != NULL; p = p->getLink())
    //     {
    //         p->display();
    //     }
    // }
};