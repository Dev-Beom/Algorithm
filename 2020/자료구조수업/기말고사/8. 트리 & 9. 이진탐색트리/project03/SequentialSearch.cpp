/*
순차탐색이란 정렬되지 않은 배열에서 탐색하고자 하는 숫자를 배열의 각 요소와
순차적으로 비교하여 탐색하는 방법을 말한다. 이진 탐색 트리의 성능을
일반배열에서의 순차 탐색과 비교해보자
(1)다음과 같은 순차 탐색 함수 sequentialSearch()를 작성한다
(2)프로그램이 시작되면 먼저 n개의 랜덤한 정수를 발생시켜 배열에 저장한다.
   가능한 평균적인 탐색 시간을 측정하기 위해 역시 랜덤한 수를 r개 발생시키고(r은 10 내외),
   각각을 배열에서 순차 탐색으로 찾고 실행시간을 측정한다. 이 때 반드시 탐색 연산에
   걸린 시간만을 측정해야하는 것에 주의한다. sequentialSearch() 함수의 호출전과 호출 후의 시각을
   저장하면 될 것이다. 탐색에 걸린 평균 시간을 계산한다. 같은 실험을 n이 10000부터 10000씩 증가시키면서
   반복한다.
(3) 동일한 실험을 이진탐색트리를 이용하여 반복한다. O(logn)이 O(n)보다 빠른 것을 보이면 된다.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "BinSrchTree.h"

using namespace std;
 
int sequentialSearch(int list[], int n, int key, int idx)
{
        for (int i = 0; i < n; i++)
               if (list[i] == key)
                       return i;
        return -1;
}
 
int main(void)
{
        BinSrchTree tree;
        int arr[100000] = { 0 };
        int search[10] = { 0 };
        float arrayTime=0.0, BSTTime = 0.0;
        int n = 10000;
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++)
        {
               int random = rand();
               arr[i] = random;
               printf("%d\n", arr[i]);
               tree.insert(new BinaryNode(random));
        }
        for (int i = 0; i < 10; i++)
        {
               int before;
               if (i)
               {
                       for (int j = before; j < n; j++)
                       {
                              int random = rand();
                              arr[j] = random;
                              tree.insert(new BinaryNode(random));
                       }
               }
               for (int j = 0; j < 10; j++)
               {
                       search[j] = rand();
               }
               clock_t start = clock();
               for (int j = 0; j < 10; j++)
               {
                       if (sequentialSearch(arr, n, search[j], 0) == -1)
                              cout << j + 1 << "번째 시도 탐색 실패" << endl;
                       else
                              cout << j + 1 << "번째 시도 탐색 성공 " << endl;
               }
               arrayTime += (float)(clock() - start) / CLOCKS_PER_SEC;
               start = clock();
               for (int j = 0; j < 10; j++)
               {
                       tree.search(search[j]);
               }
               BSTTime += (float)(clock() - start) / CLOCKS_PER_SEC;
               before = n;
               n += 10000;
        }
        cout << "배열탐색에 걸린 평균 시간=" << (float)arrayTime/10 << endl;
        cout << "이진트리탐색에 걸린 평균 시간=" << (float)BSTTime/10 << endl;
        return 0;
}