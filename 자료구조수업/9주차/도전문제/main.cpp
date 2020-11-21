/*
NOTE 이진트리 테스트 프로그램

                A
              /   \
            B       C
          /       /   \
        D       E       F
              /   \
            G       H

*/
#include "BinaryTree.h"

int main(int argc, char const *argv[])
{
    BinaryTree tree;
    
    BinaryNode *d = new BinaryNode('D', NULL, NULL);
    BinaryNode *b = new BinaryNode('B', d, NULL);
    
    BinaryNode *g = new BinaryNode('G', NULL, NULL);
    BinaryNode *h = new BinaryNode('H', NULL, NULL);

    BinaryNode *e = new BinaryNode('E', g, h);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);

    BinaryNode *c = new BinaryNode('C', e, f);

    BinaryNode *a = new BinaryNode('A', b, c);

    tree.setRoot(a);

    printf("순회결과를 출력합니다.\n");
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    printf("전체 노드갯수(%d)\n", tree.getCount());
    printf("단말노드 개수(%d)\n", tree.getLeafCount());
    printf("트리의 높이(%d)\n", tree.getHeight());
    return 0;
}
