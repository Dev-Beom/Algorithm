// Node.h : 인접 리스트를 이용한 그래프를 위한 노드 클래스

#pragma once
#include <stdio.h>

class Node
{
protected:
    int id;         //  정점의 id
    Node *link;     //  다음 노드의 포인터

public:
    Node(int i, Node *l = NULL) : id(i), link(l) {}
    ~Node()
    {
        if (link != NULL)
            delete link;
    }
    int getId() { return id; }
    Node *getLink() { return link; }
    void setLink(Node *l) { link = l; }
};