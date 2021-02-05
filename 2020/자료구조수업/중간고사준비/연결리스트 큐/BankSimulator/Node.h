#pragma once

#include <stdio.h>
#include "Customer.h"

class Node
{
private:
    Node *link;
    Customer data;

public:
    Node(Customer val = 0) : data(val), link(NULL) {}
    Node *getLink()
    {
        return link;
    }

    void setLink(Node *next)
    {
        link = next;
    }

    Customer getData()
    {
        return data;
    }
};