/*
NOTE
단순 연결리스트 테스트 프로그램
*/

#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList list;
    LinkedList list2;
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.size(), new Node(40));
    list.insert(2, new Node(50));
    list2.insert(0, new Node(20));
    list2.insert(0, new Node(30));
    list2.insert(0, new Node(40));

    cout << "list:";
    list.display();

    cout << "list2: ";
    list2.display();

    cout << "list와 list2를 합친 결과" << endl;
    list.merge(&list2);

    cout << "list:";
    list.display();

    cout << "list2: ";
    list2.display();

    cout << "list Sum: ";
    list.sum();

    cout << "list내 90을 갖고 있는 노드의 수: " << list.count(90) << endl;
    cout << "list 역순: ";
    list.reverse();
    list.display();
    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, new Node(90));
    list.display();
    cout << "list 내 90을 갖고 있는 노드의 수: "<< list.count(90) << endl;
    list.clear();
    list.display();
    return 0;
}
