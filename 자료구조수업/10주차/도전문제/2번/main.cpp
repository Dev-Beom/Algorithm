/*
NOTE
STL의 우선순위큐를 이용한 정렬을 구현하고, 내림차순(decreasing) 정렬을 테스트하세요.
*/

#include "stdio.h"
#include <queue>
#include <functional>
#include <cstdlib>

using namespace std;

/*
내림차순으로 힙 정렬을 하는 함수.
정렬하고자 하는 배열과, 배열의 요소 개수를 전달받습니다.
*/
void heapSortDec(int a[], int n)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
        maxHeap.push(a[i]);

    for (int i = 0; i < n; i++)
    {
        a[i] = maxHeap.top();
        maxHeap.pop();
    }
}

/*
오름차순으로 힙 정렬을 하는 함수.
정렬하고자 하는 배열과, 배열의 요소 개수를 전달받습니다.
*/
void heapSortAsc(int a[], int n)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
        maxHeap.push(a[i]);

    for (int i = 0; i < n; i++)
    {
        a[n - (i + 1)] = maxHeap.top();
        maxHeap.pop();
    }
}

int main(int argc, char const *argv[])
{
    int data[10];
    for (int i = 0; i < 10; i++)
        data[i] = rand() % 100;
    printf("\n정렬 전:");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);

    heapSortDec(data, 10);
    // heapSortAsc(data, 10);

    printf("\n정렬 후:");
    for (int i = 0; i < 10; i++)
        printf("%3d", data[i]);
    return 0;
}
