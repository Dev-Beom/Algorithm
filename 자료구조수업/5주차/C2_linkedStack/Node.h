#pragma once

#include "Student.h"

class Node : public Student
{
    Node *link; //  다음 노드를 가리키는 포인터 변수. 즉, 노드가 가리키는 주소 값

public:
    Node(int id = 0, char *name = "", char *dept = "") : Student(id, name, dept) { link = NULL; }
    
    Node *getLink() //  현재 노드가 가리키는 주소값을 반환한다.
    {
        return link;
    }
    
    void setLink(Node *nextP)   //  현재 노드가 가리키는 주소값을 nextP라는 다른 주소값으로 바꾼다.
    {
        link = nextP;
    }
};