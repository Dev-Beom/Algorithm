#include "StudentStack.h"

int main(void)
{
    StudentStack stack;
    stack.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(Student(2015130008, "홍길동", "컴퓨터공학과"));
    stack.push(Student(2015130009, "홍길동", "컴퓨터공학과"));
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}
