#include "AdjListGraph.h"
#include "CircularQueue.h"
class SrchALGraph : public AdjListGraph
{
    bool visited[MAX_VTXS];                     // 정점의 방문 정보

public:
    void resetVisited()                         // 모든 정점을 방문하지 않았다고 설정
    {
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }
    }
    bool isLinked(int u, int v)
    {
        for (Node *p = adj[u]; p != NULL; p = p->getLink())        
        {
            if (p->getID() == v)
                return true;
        }
        return false;
    }

    // 깊이 우선 탐색
    void DFS(int v){
        visited[v] = true;
        printf("%c ", getVertex(v));

        for( Node *p = adj[v]; p != NULL; p=p->getLink()){
            if(visited[p->getID()] == false){
                DFS(p->getID());
            }
        }
    }

    // 너비 우선 탐색
    void BFS(int v){
        visited[v] = true;
        printf("%c ", getVertex(v));

        CircularQueue que;
        que.enqueue(v);

        while(!que.isEmpty()){
            int v = que.dequeue();
            for( Node *w=adj[v]; w!=NULL; w=w->getLink()){
                int id= w->getID();
                if(!visited[id]){
                    visited[id] = true;
                    printf("%c ", getVertex(id));
                    que.enqueue(id);
                }
            }
        }
    }
};
