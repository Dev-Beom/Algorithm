#include "HeapNode.h"
#define Min_ELEMENT 200

class MinHeap
{
    HeapNode node[Min_ELEMENT];
    int size;

public:
    MinHeap() : size(0) {}
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == Min_ELEMENT - 1; }

    HeapNode &getParent(int i) { return node[i / 2]; }    // 부모 노드
    HeapNode &getLeft(int i) { return node[i * 2]; }      // 왼쪽 자식 노드
    HeapNode &getRight(int i) { return node[i * 2 + 1]; } // 오른쪽 자식 노드

    void insert(int key)
    {
        if(isFull()) return;        //포화 상태인 경우
        int i = ++size;
        while( i != 1 && key < getParent(i).getKey()){      // 루트가 1이 아니고 부모 노드보다 키 값이 클 때
            node[i] = getParent(i);
            i/=2;
        }
        node[i].setKey( key );
    }

    HeapNode remove()
    {
        if(isEmpty()) return NULL;
        HeapNode root = node[1];        // 루트 노드 (꺼낼 요소)
        HeapNode last = node[size--];   // 힙의 마지막 노드
        int parent = 1;                 // 마지막 노드의 위치를 루트로 생각함
        int child = 2;                  // 루트의 왼쪽 자식 위치

        while( child <= size){      //힙 트리를 벗어나지 않는 동안
        // 현재 노드의 자식 중 더 큰 자식 노드를 찾음
            if( child < size && getLeft(parent).getKey() > getRight(parent).getKey()){
                child++; 
            }
            if(last.getKey() <= node[child].getKey()){
              break;
            }
            node[parent] = node[child];
            parent = child;
            child *= 2;
        }
        node[parent] = last;
        return root;
    }
};