/*
가장 간단한 방법의 미팅 주선 프로그램을 만들려고 한다.
남학생과 여학생의 큐를 각각 만들어 학생이 등록하면 큐에 넣는다.
가장 먼저 등록한 남학생과 여학생을 뽑아 미팅을 주선하는 일을 반복한다.
만약 여학생 큐가 비었거나 남학생 큐가 비었으면 한쪽 큐에 있는 학생들은 기다려야 한다.
 
조건
(1) 등록한 학생 정보를 수동으로 입력하도록 사용자 인터페이스를 완성하라
(2) 원형 큐를 사용하여 남학생 큐와 여학생 큐를 구현해보라
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

class CircularStudent
{
protected:
    int front; //첫 번째 요소 앞의 위치
    int rear;  //마지막 요소 위치
    char **data;

public:
    CircularStudent()
    {
        front = rear = 0;
        data = new char *[MAX_QUEUE_SIZE];
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            data[i] = new char[20];
    }
    ~CircularStudent()
    {
        for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            delete[] data[i];
        delete[] data;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }
    void enqueue(char *name) //큐에 삽입
    {
        if (isFull())
            error("error:큐가 포화상태입니다\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            strcpy(data[rear], name);
        }
    }
    char *dequeue() //첫 항목을 큐에서 빼서 반환
    {
        if (isEmpty())
            error("Error: 큐가 공백상태입니다\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    char *peek() //첫 항목을 큐에서 빼지 않고 반환
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
