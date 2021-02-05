/*
힙을 이용하지 않고 우선순위 큐를 작성하려고 한다.
정렬되지 않은 1차원 배열을 이용해 우선순위 큐 클래스
MaxPriorityQueue를 다음과 같이 작성한다.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX_ELEMENT 100
class MaxPriorityQueue
{
private:
    int elem[MAX_ELEMENT]; //요소의 배열
    int size;              //현재 요소의 개수

public:
    MaxPriorityQueue() { size = 0; }

    int getParent(int i)
    {
        return i / 2;
    }

    int getLeft(int i)
    {
        return i * 2;
    }

    int getRight(int i)
    {
        return i * 2 + 1;
    }

    void insert(int data) //삽입 함수
    {
        if (size == MAX_ELEMENT)
            return;
        int i = ++size;
        while (i != 1 && data > elem[getParent(i)]) //루트가 아니고 부모노드보다 값이 크면
        {
            elem[i] = elem[getParent(i)]; //부모를 자식노드로 끌어내리고
            i /= 2;                       //한 레벨 상승
        }
        elem[i] = data;
    }

    int remove() //최대 항목 삭제 및 반환 함
    {
        if (!size)
            return NULL;
        int root = elem[1];
        int last = elem[size--];
        int parent = 1;
        int child = 2;
        while (child <= size)
        {
            if (child < size && elem[getParent(parent)] < elem[getParent(parent)])
                child++;
            if (elem[last] >= elem[child])
                break;
            elem[parent] = elem[child];
            parent = child;
            child *= 2;
        }
        elem[parent] = last;
        child *= 2;
    }

    int find() //최대 항목 반환 함수
    {
        return elem[1];
    }

    void display() //우선순위 큐의 모든 항목 출력
    {
        int res = 1;
        int square = 2;
        int height = 1;
        int start = 0;
        while (res <= size)
        {
            res *= 2;
            height++;
        }
        for (int i = 1; i <= size; i++)
        {
            if (i == 1 || i == square)
            {
                cout << endl;
                for (int j = start; j < height; j++)
                    cout << "    ";
                if (i != 1)
                    square *= 2;
                start++;
            }
            cout << elem[i];
            for (int j = 0; j < height - start; j++)
            {
                if (i % 2)
                    cout << "  ";
                else
                    cout << "    ";
            }
        }
        cout << endl;
    }
};

int main(void)
{
    MaxPriorityQueue q;

    int arr[10];

    srand((unsigned)time(NULL));

    cout << "정렬 안된 배열: ";

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << "우선순위 큐" << endl;

    for (int i = 0; i < 10; i++)
        q.insert(arr[i]);

    q.display();
    
    return 0;
}