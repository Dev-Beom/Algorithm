/*
(1)정점의 수와 간선의 수를 입력하면 무작위로 그래프를 발생시키는 함수를 구현하라.
단, 정점 사이에 중복된 간선이 존재하지 않아야 한다. 생성된 그래프를 화면에 출력하고, 파일에 저장하라.
정점의 이름은 'A'로부터 시작하여 하나씩 증가시키도록 한다.
 
(2) (1)을 이용하여 무작위로 그래프를 발생시키고 프로그램 11.13의 연결 성분 탐색을 참고하여 연결된 성분의 개수를 출력하라
 
(3) (1) 알고리즘을 보완하여 모든 정점이 연결된 "연결 그래프"를 무작위로 발생시키는 다음 함수를 구현한다.
    (2) 와 같이 연결된 성분의 개수가 1이 되는지 확인한다.
*/
#include "ConnectedComponentGraph.h"

int main(void)
{
    ConnectedComponentGraph g, g2;
    int numVtx, numEdge;
    srand((unsigned)time(NULL));
    cout << "정점의 개수 입력: ";
    cin >> numVtx;
    do
    {
        cout << "간선의 개수 입력:(정점의 개수 두배를 넘어서면 안된다) ";
        cin >> numEdge;
    } while (numEdge > 2 * numVtx);
    g.randomGraph(numVtx, numEdge);
    cout << "그래프 출력" << endl;
    g.display();
    g.store("graph.txt");
    cout << endl
         << "연결 성분 테스트 그래프" << endl;
    g.resetVisited();
    g.findConnectedComponent();
    cout << endl
         << endl
         << "연결 그래프 생성" << endl;
    g2.randomConnectedGraph(numVtx);
    cout << endl
         << "연결 성분 테스트 그래프" << endl;
    g2.resetVisited();
    g2.findConnectedComponent();
    return 0;
}