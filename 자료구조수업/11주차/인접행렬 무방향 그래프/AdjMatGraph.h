#include <cstdio>
#define MAX_VTXS 256                // 표현 가능한 최대 정점의 개수

class AdjMatGraph
{
protected:
    int size;                       // 정점의 개수
    char vertices[MAX_VTXS];        // 정점의 이름
    int adj[MAX_VTXS][MAX_VTXS];    // 인접 행렬

public:
    AdjMatGraph() { reset(); }
    char getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX_VTXS; }

    // 그래프 초기화 ==> 공백 상태의 그래프
    void reset()
    {
        size = 0;
        for (int i = 0; i < MAX_VTXS; i++)
        {
            for (int j = 0; j < MAX_VTXS; j++)
            {
                setEdge(i, j, 0);
            }
        }
    }

    // 정점 삽입
    void insertVertex( char name ) {
        if( !isFull() ) vertices[size++] = name;
        else printf("Error: 그래프 정점 개수 초과\n");
    }

    // 간선 삽입: 무방향 그래프의 경우임. (방향, 가중치 그래프에서는 수정)
    void insertEdge( int u, int v ){
        setEdge(u,v,1);
        setEdge(v,u,1);
    }

    // 그래프 정보 출력 (화면이나 파일에 출력)
    void display (FILE *fp = stdout){
        fprintf(fp, "%d\n", size);
        for( int i = 0; i < size; i++){
            fprintf(fp, "%c ", getVertex(i));
            for(int j = 0; j < size; j++){
                fprintf(fp, "%3d", getEdge(i,j));
            }
            fprintf(fp, "\n");
        }
    }
};