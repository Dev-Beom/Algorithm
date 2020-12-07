/*
9.2절에서 이진 탐색 트리의 탐색 연산을 트리 클래스에서 구현했고 노드 클래스에서도 구현해 보았다.
트리의 각 노드들을 모두 자신을 루트로 하는 서브트리를 대표한다고 보면 많은 트리의 연산들을 노드에서 구현할 수 있다.
8장의 프로그램 8.1과 프로그램 8.2를 수정하여 BinaryTree 클래스에서 구현했던 다음 멤버함수들을 BinaryNode 클래스에서 구현해라.
void BinaryNode::inorder();
void BinaryNode::preorder();
void BinaryNode::postorder();
//아래 세 함수는 고민을 해봐도 BinaryNode *root 없이 어떻게 구현해야할지 모르겠습니다
//그리고 굳이 BinaryNode.h에서 구현해야하나 싶어 구현하지 않았습니다
int BinaryNode::getCount();
int BinaryNode::getHeight();
int BinaryNode::getLeafCount();
*/

#include <iostream>

using namespace std;

class BinaryNode
{

protected:
    int data;
    BinaryNode *left;
    BinaryNode *right;

    void inorder(int data)
    {
        if (left != NULL)
            left->inorder();
        cout << (char)data << " ";
        if (right != NULL)
            right->inorder();
    }

    void preorder(int data)
    {
        cout << (char)data << " ";
        if (left != NULL)
            left->preorder();
        if (right != NULL)
            right->preorder();
    }

    void postorder(int data)
    {
        if (left != NULL)
            left->postorder();
        if (right != NULL)
            right->postorder();
        cout << (char)data << " ";
    }

public:
    BinaryNode(int val = 0, BinaryNode *l = NULL, BinaryNode *r = NULL) : data(val), left(l), right(r) {}

    BinaryNode *search(int key)
    {
        if (key == data)
            return this;
        else if (key < data && left != NULL)
            return left->search(key);
        else if (key > data && right != NULL)
            return right->search(key);
        else
            return NULL;
    }

    void setData(int val)
    {
        data = val;
    }

    void setLeft(BinaryNode *l)
    {
        left = l;
    }

    void setRight(BinaryNode *r)
    {
        right = r;
    }

    int getData()
    {
        return data;
    }

    BinaryNode *getLeft()
    {
        return left;
    }

    BinaryNode *getRight()
    {
        return right;
    }

    bool isLeaf()
    {
        return left == NULL && right == NULL;
    }

    void inorder()
    {
        inorder(data);
    }

    void preorder()
    {
        preorder(data);
    }

    void postorder()
    {
        postorder(data);
    }
};