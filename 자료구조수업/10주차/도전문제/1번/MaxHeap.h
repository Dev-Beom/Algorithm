#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200

class MaxHeap
{
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MaxHeap() : size(0) {}

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == MAX_ELEMENT - 1;
    }

    // 위치(정수)를 전달받아 위치의 부모 노드를 반환합니다.
    HeapNode &getParent(int i)
    {
        return node[i / 2];
    }

    // 위치(정수)를 절달받아 위치의 왼쪽 자식 노드를 반환합니다.
    HeapNode &getLeft(int i)
    {
        return node[i * 2];
    }

    //  위치(정수)를 전달받아 위치의 오른쪽 자식 노드를 반환합니다.
    HeapNode &getRight(int i)
    {
        return node[i * 2 + 1];
    }

    //  삽입할 key를 전달받아 key를 삽입하는 연산을 수행합니다.
    void insert(int key)
    {
        if (isFull())
            return; //  힙이 가득 찬 경우는 연산을 중지합니다.

        int i = ++size; //  증가된 힙 크기 위치에서 시작합니다.

        while (i != 1 && key > getParent(i).getKey())   //  루트가 아니고 부모보다 키 값이 큰 경우
        {
            node[i] = getParent(i); //  부모를 꿀어내리고
            i /= 2;                 //  한 레벨 위로 상승시킵니다.
        }
        node[i].setKey(key);        //  최종위치에 데이터를 복사합니다.
    }

    //  루트를 삭제하며 가장 큰 키값을 가진 노드가 반환됩니다.
    HeapNode remove()
    {
        if (isEmpty())
            return NULL;                //  힙이 비어있는 경우는 연산을 중지하고 NULL을 반환합니다.

        HeapNode root = node[1];        //  꺼낼 요소인 루트 노드.
        HeapNode last = node[size--];   //  힙의 마지막 노드.

        int parent = 1; //  마지막 노드의 위치를 루트로 가정
        int child = 2;  //  루트의 왼쪽 자식 위치.

        while (child <= size)   //  힙 트리를 벗어나지 않는 동안
        {
            if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
                child++;
            //  부모기준 오른쪽 키가 왼쪽 키보다 크면 child를 ++해줘야 한다. 이유는 1차원 배열로 되어있는데
            //  {1, 2, 3, 4, 5, 6}  1의 왼쪽은 2, 오른쪽은 3, ... 이 방식으로 되어있다. 그래서 이 방식으로 착안해 큰 값을 찾은 후 기준점을 변경해야하기 때문이다.
            

            if (last.getKey() >= node[child].getKey())  //  힙의 마지막 노드의 키값보다 작거나 같으면 반복문을 종료한다.
                break;

            //  한 단계 아래로 이동
            node[parent] = node[child]; //  부모와 자식을 전환한다.
            parent = child;             //  부모의 위치를 자식의 위치로 변환한다.
            child *= 2;                 //  자식의 위치는 현재 자식의 위치에 * 2 를 해 한 단계 아래로 이동한다.
        }
        node[parent] = last;    //  마지막 노드를 최종 위치에 저장합니다.
        return root;            //  루트 노드를 반환합니다.
    }

    HeapNode find()
    {
        return node[1];
    }

    /*
    요소를 출력해주는 함수.
    레벨 순회를 하며 출력해준다.
    */
    void display()
    {
        for (int i = 1, level = 1; i <= size; i++)
        {
            if (i == level)
            {
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n-------------------------------------");
    }
};