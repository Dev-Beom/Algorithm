/*
NOTE
단순 연결리스트를 위한 Node 클래스
앞에서 구현한 연결 리스트를 이용한 리스트 클래스를 확장하여 다음의 연산들을 추가하고 동작을 확인하라.
(1) 연결 리스트의 모든 노드의 순서를 반대로 바꾸는 연산을 구현하라
(2) 다른 리스트 객체 that의 노드 정보를 현재 리스트에 병합하는 다음 연산을 구현하라
이 연산 후 that리스트는 공백 리스트가 되어야 한다.
*/

#include <iostream>
using namespace std;

class Node
{
private:
    Node *link; //  다음 노드를 가리키는 포인터 변수
    int data;   //  노드의 데이터 필드
public:
    Node(int val = 0) : data(val), link(NULL)
    {
    }
    int getData()
    {
        return data;
    }
    Node *getLink()
    {
        return link;
    }
    void setLink(Node *next)
    {
        link = next;
    }
    void display()
    {
        cout << "<" << data << ">";
    }
    bool hasData(int val)
    {
        return data == val;
    }

    //자신의 다음에 새로운 노드 n을 삽입하는 함수
    void insertNext(Node *n)
    {
        if (n != NULL)
        {
            n->link = link;
            link = n;
        }
    }

    //자신의 다음 노드를 리스트에서 삭제하는 함수
    Node *removeNext()
    {
        Node *removed = link;
        if (removed != NULL)
            link = removed->link;
        return removed;
    }
};