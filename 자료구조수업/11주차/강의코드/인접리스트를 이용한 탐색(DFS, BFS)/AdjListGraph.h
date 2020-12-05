#pragma once
#include "Node.h"
#define MAX_VTXS	256

class AdjListGraph
{
	int		size;				// 정점의 개수
	char	vertices[MAX_VTXS];	// 정점 정보 (응용에 따라 확장 필요)
	Node*	adj[MAX_VTXS];		// 각 정점의 인접 리스트

public:
	AdjListGraph(void) : size(0) { }
	~AdjListGraph(void){ reset(); }

	void reset(void) { 
		for( int i=0 ; i<size ; i++ ) 
			if( adj != NULL ) delete adj[i];
		size = 0;
	}
	bool isEmpty()			{ return (size==0); }
	bool isFull()			{ return (size>=MAX_VTXS); }
	char getVertex(int i)	{ return vertices[i]; }

	void insertVertex( char val ) {
		if( !isFull() ) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}

	void insertEdge( int u, int v) {
		adj[u] = new Node (v, adj[u]);
		adj[v] = new Node (u, adj[v]);
	}

	void display( ) {
		printf("%d\n", size);				
		for( int i=0 ; i<size ; i++ ) {		
			printf("%c  ", getVertex(i));	

			for( Node *v=adj[i] ; v != NULL ; v=v->getLink() )
				printf("   %c", getVertex(v->getId()) );
			printf("\n");
		}
	}

	void load(char *filename) {
		FILE *fp = fopen(filename, "r");
		if( fp != NULL ) {
			int n, val;
			fscanf(fp, "%d", &n);			
			for(int i=0 ; i<n ; i++ ) {
				char	str[80];
				int		val;
				fscanf(fp, "%s", str);		
				insertVertex( str[0] );		
				for(int j=0 ; j<n ; j++){
					fscanf(fp, "%d", &val);	
					if( val != 0 )			
						insertEdge (i,j);	
				}
			}
			fclose(fp);
		}
	}
};

