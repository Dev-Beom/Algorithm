
#include "BinSrchTree.h"

int main(int argc, char const *argv[])
{
    BinSrchTree tree;
    BinaryNode *n1 = new BinaryNode(6, NULL, NULL);
    BinaryNode *n2 = new BinaryNode(8, NULL, NULL);
    BinaryNode *n3 = new BinaryNode(7, n1, n2);

    BinaryNode *n4 = new BinaryNode(2, NULL, NULL);
    BinaryNode *n5 = new BinaryNode(1, NULL, n4);
    BinaryNode *n6 = new BinaryNode(4, NULL, NULL);

    BinaryNode *n7 = new BinaryNode(3, n5, n6);

    BinaryNode *n8 = new BinaryNode(9, n3, NULL);

    BinaryNode *n9 = new BinaryNode(5, n7, n8);
    tree.setRoot(n9);

    printf("순회결과를 출력합니다.\n");
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();


    printf("전체 노드갯수(%d)\n", tree.getCount());
    printf("단말노드 개수(%d)\n", tree.getLeafCount());
    printf("트리의 높이(%d)\n", tree.getHeight());

    tree.remove(9);
    tree.levelorder();
    return 0;
}
