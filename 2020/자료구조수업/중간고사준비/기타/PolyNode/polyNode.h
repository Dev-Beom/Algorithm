#include <iostream>

using namespace std;

class Node
{
private:
    float coef;
    int exp;
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
        if (exp >= 0)
        {
            cout << coef << "x^" << exp << " ";
        }
    }
    void maxDisplay()
    {
        cout << "최고차수는" << exp << "이고, 그 항의 계수는 " << coef << "이다." << endl;
    }

    void insertNext(Node *n)
    {
        if (n != NULL)
        {
            n->link = link;
            link = n;
        }
    }

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