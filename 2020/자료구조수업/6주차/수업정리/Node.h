
#include <iostream>

class Node
{
    Node *link;
    int data;

public:
    Node(int val = 0) : data(val), link(NULL) {}
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
        printf(" <%2d>", data);
    }

    bool hasData(int val)
    {
        return data == val;
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
};