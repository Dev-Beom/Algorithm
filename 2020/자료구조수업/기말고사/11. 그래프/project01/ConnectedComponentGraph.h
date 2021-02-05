/*
인접 배열을 이용한 그래프의 연결 성분 탐색 프로그램
*/

#include "SrchAMGraph.h"
 
class ConnectedComponentGraph :public SrchAMGraph
{
private:
        int label[MAX_VTXS]; //정점의 색상 필드 추가

public:
        //깊이 우선 탐색
        void labelDFS(int v, int color)
        {
               visited[v] = true;
               label[v] = color;
               for (int w = 0; w < size; w++)
                       if (isLinked(v, w) && visited[w] == false)
                              labelDFS(w, color);
        }

        //그래프의 연결 성분 검출 함수
        void findConnectedComponent()
        {
               int count = 0;
               for (int i = 0; i < size; i++)
                       if (visited[i] == false)
                              labelDFS(i, ++count);
               cout << "그래프의 연결 성분 개수==" << count << endl;
               for (int i = 0; i < size; i++)
                       cout << getVertex(i) << "=" << label[i] << " ";
               cout << endl;
        }
};