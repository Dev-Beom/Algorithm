#include "HeapNode.h"
#include "MaxHeap.h"
#include <cstdlib>

void heapSort(int a[], int n)
{
    MaxHeap h;
    for (int i = 0; i < n; i++)
        h.insert(a[i]);

    for (int i = n - 1; i >= 0; i--)
        a[i] = h.remove().getKey();
}

int main(int argc, char const *argv[])
{
    MaxHeap heap;
    int data[10];

    for (int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    printf("\n정렬 전:");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);

    heapSort(data, 10);


    printf("\n정렬 후:");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    return 0;
}
