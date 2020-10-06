#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(char *str)
{
    cout << str << endl;
    exit(1);
}

class CircularQueue
{
private:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

public:
    CircularQueue(/* args */);
    ~CircularQueue();

    bool isEmpty();
    bool isFull();
    void enqueue(int val);
    int dequeue();
    int peek();
    void display();
};

CircularQueue::CircularQueue(/* args */)
{
    front = 0;
    rear = 0;
}

CircularQueue::~CircularQueue() {}
bool CircularQueue::isEmpty()
{
    return front == rear;
}
bool CircularQueue::isFull()
{
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void CircularQueue::enqueue(int val)
{
    if (isFull())
    {
        error("error: 큐가 포화상태입니다.\n");
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        data[rear] = val;
    }
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        error("Error: 큐가 공백상태입니다.\n");
    }
    else
    {
        front = (front + 1) % MAX_QUEUE_SIZE;
        return data[front];
    }
}

int CircularQueue::peek()
{
    if (isEmpty())
    {
        error("Error: 큐가 공백상태입니다\n");
    }
    else
    {
        return data[(front + 1) % MAX_QUEUE_SIZE];
    }
}

void CircularQueue::display()
{
    cout << "큐의 내용: ";
    int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
    for (int i = front + 1; i <= maxi; i++)
    {
        cout << data[i % MAX_QUEUE_SIZE] << "";
    }
    cout << endl;
}