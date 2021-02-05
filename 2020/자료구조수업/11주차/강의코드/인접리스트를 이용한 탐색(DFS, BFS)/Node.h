#pragma once
#include <stdio.h>

class Node
{
protected:
	int		id;		// 정점의 id
	Node*	link;	// 다음 노드의 포인터
public:
	Node( int i, Node *l=NULL ) : id(i), link(l) { }
	~Node(void) { 
		if( link != NULL )
			delete link;
	}
	int	  getId()			{ return id; }
	Node* getLink()			{ return link; }
	void setLink(Node* l)	{ link = l; }
};

