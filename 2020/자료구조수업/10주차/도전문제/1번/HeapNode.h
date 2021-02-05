#pragma once
#include <stdio.h>

class HeapNode
{
    int key;

public:
    HeapNode(int key = 0) : key(key) {}
    ~HeapNode() {}

    void setKey(int k)
    {
        key = k;
    }
    
    int getKey()
    {
        return key;
    }
    void display()
    {
        printf("\t%d", key);
    }
};