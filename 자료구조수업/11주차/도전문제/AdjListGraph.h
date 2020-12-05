#include "Node.h" //  연결 리스트를 위한 노드 그래프 클래스 포함

#define MAX_VTXS 20

class AdjListGraph
{
protected:
    int size;                //  정점의 개수
    char vertices[MAX_VTXS]; //  정점 정보 (응용에 따라 확장이 필요하다.)
    Node *adj[MAX_VTXS];     //  각 정점의 인접 리스트

public:
    AdjListGraph() : size(0){};
    ~AdjListGraph() { reset(); }
    bool isEmpty() { return (size == 0); }
    bool isFull() { return (size >= MAX_VTXS); }
    char getVertex(int i) { return vertices[i]; }
    int getSize() { return size; }

    void reset(void)
    {
        for (int i = 0; i < size; i++)
        {
            if (adj[i] != NULL)
                delete adj[i];
        }
    }

    void resetVisited()
    {
        for (int i = 0; i < size; i++)
        {
            if (adj[i] != NULL)
            {
                adj[i]->setLink(NULL);
            }
        }
    }

    void insertVertex(char val) //  정점 삽입 연산
    {
        if (!isFull())
        {
            vertices[size] = val;
            adj[size++] = NULL;
        }
        else
        {
            printf("Error: 그래프 정점 개수 초과\n");
        }
    }

    void insertEdge(int u, int v)
    {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }

    void display()
    {
        printf("%d\n", size);
        for (int i = 0; i < size; i++)
        {
            printf("%c ", getVertex(i));
            for (Node *v = adj[i]; v != NULL; v = v->getLink())
            {
                printf(" %c", getVertex(v->getId()));
                // printf("%3d", v->getId());
            }
            printf("\n");
        }
    }

    Node *adjacent(int v) { return adj[v]; }
};
