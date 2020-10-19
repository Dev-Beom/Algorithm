/*
NOTE
p(x) = 10x^100 + 6과 같이 최고차상의 차수가 매우 크고
대부분 항의 계수가 0인 다항식을 희소다항식이라고 하자
이러한 다항식을 구현하기 위해 배열을 사용하면 메모리의 낭비가 심하다
따라서 희소 다항식은 연결 리스트를 이용하여 구현한 것이 좋다
*/

#include <iostream>

using namespace std;

class Node
{
private:
    float coef; //  계수
    int exp;    //  지수
    Node *link;

public:
    Node(float c = 0, int e = 0) : coef(c), exp(e), link(NULL)
    {
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
        cout << coef << "x^" << exp << "+";
    }

    //  자신의 다음에 새로운 노드 n을 삽입하는 함수
    void insertNext(Node *n)
    {
        if (n != NULL)
        {
            n->link = link;
            link = n;
        }
    }

    //  자신의 다음 노드를 리스트에서 삭제하는 함수
    Node *removeNext()
    {
        Node *removed = link;
        if (removed != NULL)
        {
            link = removed->link;
        }
        return removed;
    }
    friend class polyList;
};