/*
이진 탐색 트리를 위한 클래스
*/

#include "BinaryTree.h"
#include <iomanip>

class BinSrchTree : public BinaryTree
{
public:
    BinSrchTree(void) {}
    ~BinSrchTree(void) {}

    //이진 탐색 트리의 탐색 연산
    BinaryNode *search(int key)
    {
        BinaryNode *temp = root;
        while (temp != NULL)
        {
            if (temp->getData() == key)
            {
                cout << "탐색 성공" << endl;
                return temp;
            }
            else if (temp->getData() < key)
                temp = temp->getRight();
            else
                temp = temp->getLeft();
        }
        cout << "탐색 실패" << endl;
    }

    BinaryNode *searchRecur(BinaryNode *n, int key)
    {
        if (n == NULL)
            return NULL;
        if (key == n->getData())
            return n;
        else if (key < n->getData())
            return searchRecur(n->getLeft(), key);
        else
            return searchRecur(n->getRight(), key);
    }

    BinaryNode *searchIter(BinaryNode *n, int key)
    {
        while (n != NULL)
        {
            if (key == n->getData())
                return n;
            else if (key < n->getData())
                n = n->getLeft();
            else
                n = n->getRight();
        }
    }

    //이진 탐색 트리의 삽입 연산
    void insert(BinaryNode *n)
    {
        if (n == NULL)
            return;
        if (isEmpty())
            root = n;
        else
            insertRecur(root, n);
    }

    void insertRecur(BinaryNode *r, BinaryNode *n)
    {
        if (n->getData() == r->getData())
            return;
        else if (n->getData() < r->getData())
        {
            if (r->getLeft() == NULL)
                r->setLeft(n);
            else
                insertRecur(r->getLeft(), n);
        }
        else
        {
            if (r->getRight() == NULL)
                r->setRight(n);
            else
                insertRecur(r->getRight(), n);
        }
    }

    //이진 탐색 트리의 삭제 연산
    void remove(int key)
    {
        if (isEmpty())
            return;
        //없앨 노드와 그 노드의 부모 노드를 찾는다
        BinaryNode *parent = NULL; //없앨 노드의 부모
        BinaryNode *node = root;   //없앨 노드
        while (node != NULL && node->getData() != key)
        {
            parent = node;
            node = (key < node->getData()) ? node->getLeft() : node->getRight();
        }
        //없앨 노드가 트리에 없음
        if (node == NULL)
        {
            cout << "Error: key is not in the tree!" << endl;
            return;
        }
        //없앨 노드가 트리에 있음
        else
            remove(parent, node);
    }

    //parent를 부모로 갖는 노드 node를 이진탐색 트리에서 삭제하는 함수
    void remove(BinaryNode *parent, BinaryNode *node)
    {
        //case1:삭제하려는 노드가 단말노드일 경우
        if (node->isLeaf())
        {
            if (parent == NULL)
                root = NULL; //상속을 받은 변수를 접근해야하므로 BinaryTree.h의 멤버 변수 BinaryNode *root를 protected로 선언
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(NULL);
                else
                    parent->setRight(NULL);
            }
        }
        //case2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
        else if (node->getLeft() == NULL || node->getRight() == NULL)
        {
            //삭제할 노드의 유일한 자식노드=>child
            BinaryNode *child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
            //삭제할 노드가 루트이면==>child가 새로운 root가 됨
            if (node == root)
                root = child;
            //아니면==>부모노드의 자식으로 자식 노드 child를 직접 연결
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);
            }
        }
        //case3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우
        else
        {
            //삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색
            //succ=>후계 노드:오른쪽 서브트리에서 가장 key가 작은 노드
            //succp=>후계 노드의 부모 노드
            BinaryNode *succp = node;
            BinaryNode *succ = node->getRight();
            while (succ->getLeft() != NULL)
            {
                succp = succ;
                succ = succ->getLeft();
            }
            //후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결
            if (succp->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else //후계노드가 삭제할 노드의 바로 오른쪽 자식인 경우
                succp->setRight(succ->getRight());
            //후계 노드 정보를 삭제할 노드에 복사
            node->setData(succ->getData());
            //삭제할 노드를 후계 노드로 변경: 실제로는 후계 노드가 제거됨
            node = succ;
        }
        delete node; //메모리 동적해제
    }
};