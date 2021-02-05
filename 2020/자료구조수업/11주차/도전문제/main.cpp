//  인접 리스트를 이용한 그래프 테스트 프로그램

#include "AdjListGraph.h"

int findBridge(AdjListGraph* g)
{
    int i, j;
    int count = 0;
    g->resetVisited();

    for(i = 0; i < g->getSize(); i++)
    {
        for(j = 0; j < i; j++)
        {
        }
    }

    return count;
}


int main(int argc, char const *argv[])
{
    AdjListGraph g;

    for (int i = 0; i < 4; i++)
    {
        g.insertVertex('A' + i);
    }
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);

    printf("인접 리스트로 표현한 그래프\n");
    g.display();

    return 0;
}
