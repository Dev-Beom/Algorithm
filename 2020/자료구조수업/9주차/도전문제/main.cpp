#include <iostream>
#include "BinSrchTree.h"

// 	        6
//       2   9
//    1   4
// 8

using namespace std;

int main(int argc, char const *argv[])
{
    BinSrchTree tree;
    BinaryNode *n1 = new BinaryNode(8, NULL, NULL);
    BinaryNode *n2 = new BinaryNode(1, NULL, NULL);
    BinaryNode *n3 = new BinaryNode(4, NULL, NULL);

    BinaryNode *n4 = new BinaryNode(9, n1, NULL);
    BinaryNode *n5 = new BinaryNode(2, n2, n3);
    BinaryNode *n6 = new BinaryNode(6, n5, n4);

    tree.setRoot(n6);

    printf("전체 노드 개수 = %d\n", tree.getCount());
    printf("단말노드 개수 = %d\n", tree.getLeafCount());
    printf("트리의 높이 = %d\n", tree.getHeight());
    tree.inorder();
    printf("\n최대값 = %d\n", tree.maxNum());
    printf("최소값 = %d\n", tree.minNum());

    int input;
    cout << "사용자 입력 = ";
    cin >> input;
    tree.searchVisit(input);
    cout << "사용자 입력 = ";

    cin >> input;
    tree.searchVisit(input);
    return 0;
}
