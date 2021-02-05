/*
n개의 정점을 갖는 연결 그래프를 발생시키고 깊이 우선 탐색을 적용하여 정점을 방문하는 순서를 출력한다
*/

#include "ConnectedComponentGraph.h"
 
int main(void)
{
        srand((unsigned)time(NULL));
        ConnectedComponentGraph g;

        int n;
        cout << "정점의 개수는? ";
        cin >> n;

        g.ConnectedGraph(n);
        g.display();

        cout << "DFS: ";

        g.resetVisited();
        g.DFS(0);

        cout << endl;

        return 0;
}