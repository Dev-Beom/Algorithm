#include <stdio.h>
#include "iostream"

const int MAX_STACK_SIZE = 20;

class ArrayStack
{
private:
    int top;                  //  요소의 개수
    int data[MAX_STACK_SIZE]; //  요소의 배열

public:
    ArrayStack(/* args */); //  스택 생성자
    ~ArrayStack();          // 스택 소멸자

    bool isEmpty();
    bool isFull();

    void push(int e);
    int pop();
    int peek();
    void display();

    inline void error(char *message);
};

ArrayStack::ArrayStack(/* args */) //   스택 생성자
{
    top = -1;
}

ArrayStack::~ArrayStack() //    스택 소멸자
{
}

bool ArrayStack::isEmpty()
{
    return top == -1;
    //  top == -1 => true 
    //  top != -1 => false
}

bool ArrayStack::isFull()
{
    return top == MAX_STACK_SIZE - 1;
    //  top == MAX_STACK_SIZE - 1 => true
    //  top != MAX_STACK_SIZE - 1 => false
}

inline void ArrayStack::error(char *message)    //  오류 처리 함수
{
    printf("%s\n", message);
    exit(1);
}

void ArrayStack::push(int e)
{
    if (isFull())
    {
        error("스택 포화 에러");
    }
    data[++top] = e;
}

int ArrayStack::pop()   //  맨 위의 요소를 삭제하고 반환
{
    if (isEmpty())
    {
        error("스택 공백 에러");
    }
    return data[top--];
}

int ArrayStack::peek()  //  삭제하지 않고 요소 반환
{
    if (isEmpty())
    {
        error("스택 공백 에러");
    }
    return data[top];
}

void ArrayStack::display()  //  스택 내용을 화면에 출력
{
    printf("[스택 항목의 수 = %2d] ==> ", top + 1);
    for (int i = 0; i <= top; i++)
    {
        printf("<%2d>", data[i]);
    }
    printf("\n");
}