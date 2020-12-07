#include "AdjListGraph.h"

int main(int argc, char const *argv[])
{
	AdjListGraph g;

	//g.load("graph.txt");
	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i); // 정점 삽입: 'A' 'B', ...

	g.insertEdge(0, 1); // 간선 삽입
	g.insertEdge(0, 3);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 3);

	printf("인접 리스트로 표현한 그래프\n");
	g.display();

	return 0;
}