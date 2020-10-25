#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList list, list2;

    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.getSize(), new Node(40));
    list.insert(2, new Node(50));
    list.display("List(전)");

    list.reverse();
    list.display("List(후)");

    list2.insert(0, new Node(70));
    list2.insert(1, new Node(80));
    list2.insert(2, new Node(90));
    list2.display("List(that)");

    list.merge(&list2);
    list.display("List(reverse + that)");
    list2.display("List(that)");

    list.clear();
    list2.clear();
    list.display("List(끝)");
    return 0;
}