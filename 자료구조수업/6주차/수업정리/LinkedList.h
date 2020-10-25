#include <iostream>

#include <string>
#include "Node.h"

class LinkedList
{
    Node org; //  헤드 노드

public:
    LinkedList() : org(0) {}
    ~LinkedList()
    {
        clear();
    }

    Node *getHead()
    {
        return org.getLink();
    }

    bool isEmpty()
    {
        return getHead() == NULL;
    }

    void clear()
    {
        while (!isEmpty())
        {
            delete remove(0);
        }
    }

    //  pos번째 항목을 반환함
    Node *getEntry(int pos)
    {
        Node *n = &org;
        for (int i = -1; i < pos; i++, n = n->getLink())
        {
            if (n == NULL)
            {
                break;
            }
        }
        return n;
    }

    //  리스트의 어떤 위치에 항목 삽입
    void insert(int pos, Node *n)
    {
        Node *prev = getEntry(pos - 1);
        if (prev != NULL)
        {
            prev->insertNext(n);
        }
    }

    //  리스트의 어떤 위치의 항목 삭제
    Node *remove(int pos)
    {
        Node *prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    //  리스트의 항목값을 변경
    void replace(int pos, Node *n)
    {
        remove(pos);
        insert(pos, n);
    }

    //모든 노드의 순서를 반대로 바꿈
    void reverse()
    {
        int count = 0;
        for (int i = 0; i < getSize(); i++)
        {
            Node *tmp = remove(getSize() - 1);
            insert(count++, tmp);
        }
    }

    //다른 리스트 객체 that의 노드 정보를 현재 리스트에 병합
    void merge(LinkedList *that)
    {
        while (!that->isEmpty())
        {
            Node *tmp = that->remove(0);
            insert(getSize(), tmp);
        }
    }

    //  화면에 보기 좋게 출력
    void display(std::string _text)
    {
        std::cout << _text;
        printf("[전체 항목 수 = %2d] : ", getSize());
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            p->display();
        }
        printf("\n");
    }

    //  list의 사이즈를 반환
    int getSize()
    {
        int length = 0;
        for (Node *p = getHead(); p != NULL; p = p->getLink())
        {
            length++;
        }
        return length;
    }
};