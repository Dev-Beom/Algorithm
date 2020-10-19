#include "CircularList.h"

int main(int argc, char const *argv[])
{
    CircularList list;
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(list.size(), new Node(40));
    list.insert(2, new Node(50));
    list.display();
    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.display();
    list.clear();
    list.display();
    
    return 0;
}
