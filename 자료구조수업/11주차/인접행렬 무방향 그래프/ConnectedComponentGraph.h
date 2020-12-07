#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph
{
    int label[MAX_VTXS];            //  정점의 색상 필드 추가

public:
    void labelDFS(int v, int color)
    {
        visited[v] = true;          //  현재 정점을 방문함
        label[v] = color;           //  현재 정점의 색상
        for (int w = 0; w < size; w++)
        {
            if (isLinked(v, w) && visited[w] == false)
            {
                labelDFS(w, color);
            }
        }
    }

    void findConnectedComponent()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (visited[i] == false)
            {
                labelDFS(i, ++count);
            }
        }
        printf("그래프 연결성분 개수 = = %d\n", count);
        for (int i = 0; i < size; i++)
        {
            printf(" %c = %d ", getVertex(i), label[i]);
        }
        printf("\n");
    }
};
