// #include "SrchAMGraph.h"
#include "ConnectedComponentGraph.h"

int main(int argc, char const *argv[])
{
    // SrchAMGraph g;

    ConnectedComponentGraph g;

    for (int i = 0; i < 4; i++)
    {
        g.insertVertex('A' + i);
    }
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    printf("인접 행룔로 표현한 그래프\n");
    g.display();

    g.findConnectedComponent();

    printf(" DFS ==> ");
    g.resetVisited();
    g.DFS(0);
    printf("\n");

    printf(" BFS ==> ");
    g.resetVisited();
    g.BFS(0);
    printf("\n");
    return 0;
}
