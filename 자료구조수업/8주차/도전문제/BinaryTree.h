#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

class BinaryTree
{
	BinaryNode *root;

public:
	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode *node) { root = node; }
	BinaryNode *getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	void inorder()
	{
		printf("\n   inorder: ");
		inorder(root);
	}
	void preorder()
	{
		printf("\n  preorder: ");
		preorder(root);
	}
	void postorder()
	{
		printf("\n postorder: ");
		postorder(root);
	}
	void levelorder()
	{
		printf("\nlevelorder: ");
		if (!isEmpty())
		{
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty())
			{
				BinaryNode *n = q.dequeue();
				if (n != NULL)
				{
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	int getCount(BinaryNode *node)
	{
		if (node == NULL)
			return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
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
	int getHeight(BinaryNode *node)
	{
		if (node == NULL)
			return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	int calcSize() { return calcSize(root); }
	int calcSize(BinaryNode *node)
	{
		if (node == NULL)
			return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}

	int evaluate() { return evaluate(root); }
	//	수식 계산 함수
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

private:
	// 트리의 순회
	void inorder(BinaryNode *node)
	{
		if (node != NULL)
		{
			if (node->getLeft() != NULL)
				inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL)
				inorder(node->getRight());
		}
	}
	void preorder(BinaryNode *node)
	{
		if (node != NULL)
		{
			printf(" [%c] ", node->getData());
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
			printf(" [%c] ", node->getData());
		}
	}
};
