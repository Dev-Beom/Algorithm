#include "AdjMatGraph.h"
#include "CircularQueue.h"

class SrchAMGraph : public AdjMatGraph
{

protected:
    bool visited[MAX_VTXS]; // 정점의 방문 정보

public:
    void resetVisited()
    { // 모든 정점을 방문하지 않았다고 설정
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }
    }
    bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

    // 깊이 우선 탐색 함수
    void DFS(int v)
    {
        visited[v] = true;           // 현재 정점을 방문함
        printf("%c ", getVertex(v)); // 현재 정점의 이름 출력

        for (int w = 0; w < size; w++)
        {
            if (isLinked(v, w) && visited[w] == false)
            {
                DFS(w); // 연결 + 방문X => 순환 호출로 방문
            }
        }
    }
    // 너비 우선 탐색 함수
    void BFS(int v)
    {
        visited[v] = true;
        printf("%c ", getVertex(v));

        CircularQueue que;
        que.enqueue(v);
        while (!que.isEmpty())
        {
            int v = que.dequeue();
            for (int w = 0; w < size; w++)
            {
                if (isLinked(v, w) && visited[w] == false)
                {
                    visited[w] = true;
                    printf("%c ", getVertex(w));
                    que.enqueue(w);
                }
            }
        }
    }
};