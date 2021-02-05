#include "HeapNode.h"
#include "MaxHeap.h"

int main(int argc, char const *argv[])
{
    MaxHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(30);
    heap.insert(8);
    heap.insert(9);
    heap.insert(3);
    heap.insert(7);
    heap.display();

    heap.remove();
    heap.display();

    heap.remove();
    heap.display();
    return 0;
}
