/*
탐색 기능을 가진 그래프 클래스(인접 행렬 사용)
*/

#include "AdjMatGraph.h"
#include "CircularQueue.h"

class SrchAMGraph : public AdjMatGraph
{
protected:
    bool visited[MAX_VTXS]; //정점의 방문 정보

public:
    void resetVisited() //모든 정점을 방문하지 않았다고 설정
    {
        for (int i = 0; i < size; i++)
            visited[i] = false;
    }

    bool isLinked(int u, int v)
    {
        return getEdge(u, v) != 0;
    }

    //모든 정점이 연결된 "연결 그래프"를 무작위로 발생시키는 함수
    void ConnectedGraph(int numVtx)
    {
        int cnt = rand() % ((numVtx * 2) - 1) + 1;

        cout << "랜덤 연결 그래프 생성" << endl;
        cout << "간선 수: " << cnt << endl;

        for (int j = 0; j < numVtx; j++)
            insertVertex('A' + j);

        int first = rand() % numVtx;
        int second;

        do
        {
            second = rand() % numVtx;
        } while (first == second);

        insertEdge(first, second);

        for (int i = 1; i < cnt; i++)
        {
            int linked = 0;
            do
            {
                first = rand() % numVtx;
                do
                {
                    second = rand() % numVtx;
                } while (first == second);
                for (int j = 0; j < numVtx; j++)
                    if (isLinked(first, j) || isLinked(second, j))
                        linked++;
            } while (getEdge(first, second) || linked == 0);
            insertEdge(first, second);
        }
    }

    //깊이 우선 탐색 함수
    void DFS(int v)
    {
        visited[v] = true;
        cout << getVertex(v) << " ";
        for (int w = 0; w < size; w++)
            if (isLinked(v, w) && visited[w] == false)
                DFS(w); //연결+방문X=> 순환 호출로 방문
    }

    //인접행렬로 표현된 그래프에 대한 너비우선탐색 연산
    void BFS(int v)
    {
        visited[v] = true;
        cout << getVertex(v) << " "; //정점의 이름 출력

        CircularQueue que;
        que.enqueue(v); //시작 정점을 큐에 저장

        while (!que.isEmpty())
        {
            int v = que.dequeue(); //큐에 정점 추출
            for (int w = 0; w < size; w++)
                if (isLinked(v, w) && visited[w] == false)
                {
                    visited[w] = true; //방문 표시
                    cout << getVertex(w) << " ";
                    que.enqueue(w);
                }
        }
    }
};