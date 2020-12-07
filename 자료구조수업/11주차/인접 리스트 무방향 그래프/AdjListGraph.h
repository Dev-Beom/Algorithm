#include "Node.h"
#include <cstdio>

#define MAX_VTXS 256

class AdjListGraph
{
protected:
    int size;                           // 정점의 개수
    char vertices[MAX_VTXS];            // 정점 정보 (응용에 따라 확장 필요)
    Node *adj[MAX_VTXS];                // 각 정점의 인접 리스트

public:
    AdjListGraph() : size(0) {}
    ~AdjListGraph() { reset(); }
    void reset()
    {
        for (int i = 0; i < size; i++)
        {
            if (adj[i] != NULL)
                delete adj[i];
            size = 0;
        }
    }
    bool isEmtpy(){ return (size == 0);}
    bool isFull() { return (size >= MAX_VTXS); }
    char getVertex(int i){ return vertices[i]; }

    // 정점 삽입 연산
    void insertVertex( char val ){
        if( !isFull() ){
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else printf("ERROR: 그래프 정점 개수 초과 \n");
    }

    // 간선 삽입 연산
    void insertEdge( int u, int v){
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }

    // 출력
    void display(){
        printf("%d\n", size);
        for(int i = 0; i < size; i++){
            printf("%c ", getVertex(i));
            for(Node* v=adj[i]; v!= NULL; v=v->getLink()){
                printf("   %c", getVertex( v->getID()) );
            }
            printf("\n");
        }
    }
    Node* adjacent(int v) { return adj[v]; }
};
