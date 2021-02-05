/*
(4)은행 서비스 시뮬레이션 프로그램을 참고하여 자동으로 시뮬레이션 할 수 있는 프로그램을 설계하고 구현하라
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(char *str)
{
    cout << str << endl;
    exit(1);
}

class CircularIntQueue
{
protected:
    int front; //첫 번째 요소 앞의 위치
    int rear;  //마지막 요소 위치
    int data[MAX_QUEUE_SIZE];

public:
    CircularIntQueue()
    {
        front = rear = 0;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }
    void enqueue(int val) //큐에 삽입
    {
        if (isFull())
            error("error:큐가 포화상태입니다\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    int dequeue() //첫 항목을 큐에서 빼서 반환
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    int peek() //첫 항목을 큐에서 빼지 않고 반환
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }
    void display() //큐의 모든 내용을 순서대로 출력
    {
        cout << "학생 : ";
        if (!isEmpty())
        {
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            for (int i = front + 1; i <= maxi; i++)
                cout << data[i % MAX_QUEUE_SIZE] << " ";
        }
        else
            cout << "학생이 아직 없습니다";
        cout << endl;
    }
};