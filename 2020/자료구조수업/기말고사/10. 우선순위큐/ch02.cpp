/*
배열로 표현된 완전 이진트리 a가 힙 조건을 만족하는지를 검사하는
다음 함수를 순환적인 방법으로 구현하고 테스트한다
*/
#include <iostream>
using namespace std;

bool isHeapRecur(int a[], int i, int size)
{
    if (i > (size - 1) / 2) //말단 노드라면
        return true;

    //자식보다 큰 값을 갖고 있다면(그 자식들도 그들의 자식보다 커야하므로 재귀)
    if (a[i] >= a[2 * i + 1] && a[i] >= a[2 * i + 2] && isHeapRecur(a, 2 * i + 1, size) && isHeapRecur(a, 2 * i + 2, size))
        return true;
    return false;
}

int main(void)
{
    int arr[11] = {0, 9, 7, 6, 5, 4, 3, 2, 2, 1, 3}; //그림 10.13
    if (isHeapRecur(arr, 1, 11))
        cout << "힙이다" << endl;
    else
        cout << "힙이 아니다" << endl;
    return 0;
}