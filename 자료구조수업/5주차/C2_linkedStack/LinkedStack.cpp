/*
연결리스트로 스택을 구현하세요(5장_2 PPT 2-5페이지와 첨부된 C5 자료 참고)
*/
#include "LinkedStack.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedStack stack;

    stack.push(new Node(20162600, "이영범", "글로벌미디어학부"));
    stack.push(new Node(20172731, "박지호", "글로벌미디어학부"));
    stack.push(new Node(19850101, "최화석", "전자계산학 "));

    /*
    NOTE
    push에는 Node *p가 들어간다.
    Node는 데이터 부분인 Student 클래스를 상속 받는다.
    따라서 동적 할당인 new Node(id, name, dept)를 통해
    값을 넣어주면 이는 Node의 생성자를 부를 것이고,
    Node의 생성자는 Student의 생성자를 부를 것이어서
    결국 Student라는 데이터에 다음 값들이 담기게 된다.
    */

    cout << stack.size() << endl;
    stack.display();
    stack.pop();
    cout << stack.size() << endl;
    stack.display();
    cout << "=================" << endl;
    Node *node = stack.pop();
    node->display();
    cout << endl;
    delete node;
    stack.display();

    return 0;
}
