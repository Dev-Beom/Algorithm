/*
이진트리 클래스의 구현
연산 추가
(1) 이진트리가 완전 이진트리인지를 검사하는 연산
(2) 임의의 node의 레벨을 구하는 연산을 구현한다, 만약 node가 트리 안에 있지 않으면 0을 반환한다.
(3) 이진트리의 모든 노드에서 왼쪽 서브트리와 오른쪽 서브트리의 높이의 차이가 2보다 작으면 이 트리를 균형잡혀있다라고 한다.
    현재 이진트리가 균형 잡혀 있는지를 검사하는 다음 연산을 구현한다.
(4) 이진트리에서 경로의 길이를 루트에서부터 모든 자식 노드까지의 경로의 길이의 합이라고 하자. 경로의 길이를 구하는 연산을 구현한다
(5) 이진트리를 좌우로 대칭시키는 연산을 구현한다
*/

#include "TreeCircularQueue.h"

class BinaryTree
{
private:
    bool reverse(BinaryNode *node)
    {
        if (node == NULL)
            return false;
        else
        {
            //재귀
            reverse(node->getLeft());
            reverse(node->getRight());

            //leftNode와 rightNode를 서로 바꾼다
            BinaryNode *temp = node->getLeft();
            node->setLeft(node->getRight());
            node->setRight(temp);
        }
        return true;
    }
    /*
        bool isBalanced(BinaryNode *node)
        {
               int leftHeight;
               int rightHeight;
 
               if (node == NULL)
                       return true;
 
               leftHeight = getHeight(node->getLeft());
               rightHeight = getHeight(node->getRight());
 
               //왼쪽 서브트리와 오른쪽서브트리의 높이차가 2이상 나지 않고 둘 다 균형이 잡혀있을 경우 참
               if ((leftHeight - rightHeight) <= 1 && (leftHeight - rightHeight) >= -1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))
                       return true;
 
               return false;
        }
        int level(BinaryNode *node1, BinaryNode *node2, int lev = 1) //node2가 우리가 찾고자 하는 node
        {
               if (node1 == NULL)
                       return 0;
               if (node1 == node2)
                       return lev;
 
               if (node1->getLeft() == NULL && node1->getRight() == NULL)
                       return 0;
               //재귀
               int left = level(node1->getLeft(), node2, lev + 1); //왼쪽으로
               int right = level(node1->getRight(), node2, lev + 1); //오른쪽으로
 
               if (!left) //왼쪽 노드가 존재하지 않는다면
                       return right; //오른쪽 노드 반환
               else //반대
                       return left;
        }
        */
    /*
        void inorder(BinaryNode *node)
        {
               if (node != NULL)
               {
                       if (node->getLeft() != NULL)
                              inorder(node->getLeft());
                       cout << "[" << (int)node->getData() << "] ";
                       if (node->getRight() != NULL)
                              inorder(node->getRight());
               }
        }
        void preorder(BinaryNode *node)
        {
               if (node != NULL)
               {
                       cout << "[" << (int)node->getData() << "] ";
                       if (node->getLeft() != NULL)
                              preorder(node->getLeft());
                       if (node->getRight() != NULL)
                              preorder(node->getRight());
               }
        }
        void postorder(BinaryNode *node)
        {
               if (node != NULL)
               {
                       if (node->getLeft() != NULL)
                              postorder(node->getLeft());
                       if (node->getRight() != NULL)
                              postorder(node->getRight());
                       cout << "[" << (int)node->getData() << "] ";
               }
        }
        */
    int getCount(BinaryNode *node)
    {
        if (node == NULL)
            return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    int getHeight(BinaryNode *node)
    {
        if (node == NULL)
            return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
    }

    int getLeafCount(BinaryNode *node)
    {
        if (node == NULL)
            return 0;
        if (node->isLeaf())
            return 1;
        else
            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    int evaluate(BinaryNode *node)
    {
        if (node == NULL)
            return 0;
        if (node->isLeaf())
            return node->getData();
        else
        {
            int op1 = evaluate(node->getLeft());
            int op2 = evaluate(node->getRight());
            switch (node->getData())
            {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
            }
            return 0;
        }
    }

    //순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수
    int calcSize(BinaryNode *node)
    {
        if (node == NULL)
            return 0;
        return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
    }

protected:
    BinaryNode *root;

public:
    BinaryTree() : root(NULL) {}

    void setRoot(BinaryNode *node) { root = node; }

    BinaryNode *getRoot() { return root; }

    bool isEmpty()
    {
        return root == NULL;
    }

    //이진트리가 완전 이진트리인지 검사하는 함수
    bool isFull()
    {
        if (!isEmpty())
        {
            CircularQueue q;
            q.enqueue(root);
            while (!q.isEmpty())
            {
                BinaryNode *n = q.dequeue();
                //말단노드가 아니고 왼쪽 오른쪽 자식 중 하나라도 없으면 완전이진트리 X
                if (!(n->isLeaf()) && n->getLeft() == NULL && n->getRight() != NULL)
                    return false;
                else if (!(n->isLeaf()) && n->getLeft() != NULL && n->getRight() == NULL)
                    return false;
                if (n != NULL)
                {
                    if (n->getLeft())
                        q.enqueue(n->getLeft());
                    if (n->getRight())
                        q.enqueue(n->getRight());
                }
            }
            return true;
        }
    }

    /*
        bool isBalanced() //균형이 잡혀있는가?
        {
               return isBalanced(root);
        }

        //뒤바꾼다
        bool reverse()
        {
               return reverse(root);
        }

        void inorder()
        {
               cout << endl << "inorder: ";
               inorder(root);
        }

        void preorder()
        {
               cout << endl << "preorder: ";
               preorder(root);
        }

        void postorder()
        {
               cout << endl << "postorder: ";
               postorder(root);
        }
        */

    void levelorder()
    {
        cout << endl
             << "levelorder: ";
        if (!isEmpty())
        {
            CircularQueue q;
            q.enqueue(root);
            while (!q.isEmpty())
            {
                BinaryNode *n = q.dequeue();
                if (n != NULL)
                {
                    cout << "[" << (int)n->getData() << "] "; //char에서 int로
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        cout << endl;
    }

    int getCount()
    {
        return isEmpty() ? 0 : getCount(root);
    }

    int getHeight()
    {
        return isEmpty() ? 0 : getHeight(root);
    }

    int getLeafCount()
    {
        return isEmpty() ? 0 : getLeafCount(root);
    }
    /*
        int evaluate()
        {
               return evaluate(root);
        }
        //디렉터리 용량 계산 함수
        int calcSize()
        {
               return calcSize(root);
        }
        //레벨을 구하는 연산
        int level(BinaryNode *node)
        {
               return level(root, node);
        }
        //경로의 길이
        int pathLength()
        {
               int sum = 0;
               if (!isEmpty())
               {
                       CircularQueue q;
                       q.enqueue(root);
                       while (!q.isEmpty())
                       {
                              BinaryNode *n = q.dequeue();
                              sum += level(n) - 1; //각 노드의 레벨-1만큼 더하면 총 경로
                              if (n != NULL)
                              {
                                      if(n->getLeft())
                                              q.enqueue(n->getLeft());
                                      if(n->getRight())
                                              q.enqueue(n->getRight());
                              }
                       }
               }
               return sum;
        }
        */
};