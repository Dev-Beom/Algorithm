/*
3번 문제의 함수를 반복적인 방법으로 구현하고 테스트한다
*/
#include <iostream>
using namespace std;

bool isHeapIter(int a[], int size)
{
    for (int i = 1; i <= (size - 1) / 2; i++) //자식이 있는 노드들만 보면 된다
    {
        //자식들보다 부모가 커야한다
        if (a[2 * i + 1] > a[i])
        {
            cout << "거짓" << i << endl;
            return false;
        }
        if (size < 2 * i + 2 && a[2 * i + 2] > a[i]) //size보다 크면 배열값이 쓰레기값이 되어 크다고 나올 수 있다
        {
            cout << "거2짓" << i << endl;
            return false;
        }
    }
    return true;
}

int main(void)
{
    int arr[11] = {0, 9, 7, 6, 5, 4, 3, 2, 2, 1, 3}; //그림 10.13
    if (isHeapIter(arr, 11))
        cout << "힙이다" << endl;
    else
        cout << "힙이 아니다" << endl;
    return 0;
}