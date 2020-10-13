#pragma once
#include "Node.h"

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
        //  소멸자, pop()을 통해 반환한 값들을 전부 삭제함.
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
        //  top: 헤드 포인터
        //  p: 이제 추가될 데이터의 주소 값을 가지고 있는 포인터
        if (isEmpty())
        {
            top = p; //  스택이 비어있으면 top이 바로 연결/
        }
        else
        {
            p->setLink(top); //  현재 삽입하고자하는 노드의 링크 필드가 기존에 있는 노드(top)를 가리키도록 함.
            top = p;         //  헤드 포인터 top이 현재 삽입하고자하는 노드를 가리키도록 함.
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
            p = top;            //  포인터변수 p가 최상단에 있는 노드를 가리키도록 함.
            top = p->getLink(); //  헤드포인터 top이 최상단 - 1 노드를 가리키게 함. p가 가리키는 링크의 값을 반환해서 top에 넣어준다. 그러면 top은 그 다음 노드를 가리키게 됨.
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
        for(Node *p = top; p != NULL; p = p->getLink())
        {
            count++;
        }
        return count;
    }

    void display()
    {
        for(Node *p = top; p != NULL; p = p->getLink())
        {
            p->display();
        }
    }
};