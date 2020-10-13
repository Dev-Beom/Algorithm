#pragma once

#include "Node.h"

class LinkedQueue
{
    Node *front;
    Node *rear;

public:
    LinkedQueue() : front(NULL), rear(NULL){};
    ~LinkedQueue()
    {
        while (!isEmpty())
        {
            delete dequeue();
        }
    }
    bool isEmpty()
    {
        return front == NULL;
        /*
        NOTE
        이제 front는 더이상 첫번째 한칸 앞을 가리키는 것이 아니라,
        첫번째 요소를 가리키는 포인터이다.
        */
    }

    void enqueue(Node *p)
    {
        if (isEmpty()) //  공백상태
        {
            front = rear = p;
            /*
            비어있으면 front와 rear을 바로 연결한다.
            NOTE
            추가될 노드의 주소를 담고있는 포인터 p의 값을
            첫번째 요소를 가리키고 있는 포인터 front와
            마지막 요소를 가리키고 있는 포인터 rear에 복사함.
            그러면 공백 상태일 때는 추가되는 노드가 시작 지점이자 마지막 지점이 된다.
            */
        }
        else //  비 공백상태
        {
            rear->setLink(p);
            /*
            1. 링크 값부터 변경해준다.
            NOTE
            추가될 노드의 주소를 담고 있는 포인터 p의 값을
            rear포인터가 가리키고 있는 직전 노드의 링크 값에 복사한다.
            그러면 이제 직전 노드의 링크에는 추가될 노드의 주소가 담기게 되어
            직전 노드는 추가될 노드를 가리키게 된다.
            */
            rear = p;
            /*
            2. rear값을 변경해준다.
            NOTE
            추가될 노드의 주소를 담고있는 포인터 p의 값을
            마지막 요소를 가리키는 포인터 rear에 넣어준다.
            */
        }
    }

    Node *dequeue()
    {
        Node *p = front;
        //  첫번째 요소의 한 칸 앞을 가리키고 있는 포인터 front의 값을
        //  이제 반환될 노드를 가리키게 될 포인터 p에 복사한다.

        if (front == rear && !isEmpty()) //  노드가 하나인 상태, front와 rear이 같고, 큐가 비어있음.
        {
            front = rear = NULL;
            /*
            NOTE
            첫번째 요소를 가리키고 있는 포인터 front와
            마지막 요소를 가리키고 있는 포인터 rear의 값을
            NULL로 바꿔준다.
            포인터가 NULL을 가리킨다는 것은 공백이라는 뜻이다.
            */
        }
        else if (front != rear) //  노드가 두개 이상인 상태, front와 rear이 같지 않음.
        {
            front = p->getLink();
            /*
            p가 가리키는 링크의 값을 반환해서 front에 넣어준다.
            그러면 front는 그 다음 노드를 가리게 된다.
            NOTE
            포인터 front에 이제 p가 가리키고 있는 삭제할 노드의 링크
            값을(즉, 삭제할 노드가 가리키고 있었던 직전 노트의 주소값) 복사한다.
            */
        }
        return p; //  p가 가리키고있는 삭제된 노드를 반환한다.
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

    void display()
    {
        for (Node *p = front; p != NULL; p = p->getLink())
        {
            p->display();
        }
    }
};
