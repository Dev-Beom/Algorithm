/*
이진트리 테스트 프로그램
*/
#include "BinaryTree.h"

int main(void)
{
    BinaryTree tree, tree2, tree3;
    BinaryNode *d = new BinaryNode('D', NULL, NULL);
    BinaryNode *e = new BinaryNode('E', NULL, NULL);
    BinaryNode *b = new BinaryNode('B', d, e);
    BinaryNode *f = new BinaryNode('F', NULL, NULL);
    BinaryNode *c = new BinaryNode('C', f, NULL);
    BinaryNode *a = new BinaryNode('A', b, c);
    tree.setRoot(a);
    //tree.inorder();
    //tree.preorder();
    //tree.postorder();
    cout << "INORDER: ";
    a->inorder();
    cout << endl;
    cout << "PREORDER: ";
    a->preorder();
    cout << endl;
    cout << "POSTORDER: ";
    a->postorder();
    cout << endl;
    /*
        tree.levelorder();
        if (tree.isFull())
               cout << "tree는 완전 이진트리이다" << endl;
        else
               cout << "tree는 완전 이진트리가 아니다" << endl;
        cout << "d의 레벨은 " << tree.level(d) << endl;
        if (tree.isBalanced())
               cout << "tree는 균형이 잡혀있다" << endl;
        else
               cout << "tree는 균형이 잡혀있지 않다" << endl;
        cout << "총 경로의 길이: " << tree.pathLength() << endl;
        if (tree.reverse())
               cout << endl << "tree reverse 완료" << endl;
        else
               cout << endl << "tree reverse 실패" << endl;
        tree.inorder();
        cout << endl;
        */
    cout << "노드의 개수= " << tree.getCount() << endl;
    cout << "단말의 개수= " << tree.getLeafCount() << endl;
    cout << "트리의 높이= " << tree.getHeight() << endl;
    /*
        BinaryNode *n1 = new BinaryNode(3, NULL, NULL);
        BinaryNode *n2 = new BinaryNode(2, NULL, NULL);
        BinaryNode *n3 = new BinaryNode('*',n1, n2);
        BinaryNode *n4 = new BinaryNode(5, NULL, NULL);
        BinaryNode *n5 = new BinaryNode(6, NULL, NULL);
        BinaryNode *n6 = new BinaryNode('-', n4, n5);
        BinaryNode *n7 = new BinaryNode('+', n3, n6);
        tree2.setRoot(n7);
        cout << "계산 결과= " << tree2.evaluate() << endl;
        BinaryNode *m4 = new BinaryNode(200, NULL, NULL);
        BinaryNode *m5 = new BinaryNode(500, NULL, NULL);
        BinaryNode *m3 = new BinaryNode(100, m4, m5);
        BinaryNode *m2 = new BinaryNode(50, NULL, NULL);
        BinaryNode *m1 = new BinaryNode(0, m2, m3);
        tree3.setRoot(m1);
        cout << "디렉터리 용량 계산 결과 = " << tree3.calcSize() << endl;
        */
    return 0;
}