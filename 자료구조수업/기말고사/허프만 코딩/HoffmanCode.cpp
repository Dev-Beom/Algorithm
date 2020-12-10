#include "MinHeap.h"

void MakeTree( int freq[], int n){
    MinHeap heap;
    for(int i = 0; i <n; i++){
        heap.insert(freq[i]);
    }
    for(int i = 1; i < n; i++){
        HeapNode e1 = heap.remove();
        HeapNode e2 = heap.remove();
        heap.insert(e1.getKey() + e2.getKey());
        printf( " (%d+%d)\n", e1.getKey(), e2.getKey());
    }
}

int main(){
    int freq[] = { 15, 12, 8, 6, 4 };
    MakeTree(freq, 5);
}