#include <stdio.h>

int arrSize = 4;
int INF = 10000000;

//  자료 배열을 초기화합니다.
int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}};

void floydWarshall()
{
    //  결과 그래프를 초기화 합니다.
    int d[arrSize][arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            d[i][j] = a[i][j];
        }
    }

    //  k = 거쳐가는 노드
    for (int k = 0; k < arrSize; k++)
    {
        //  i = 출발 노드
        for (int i = 0; i < arrSize; i++)
        {
            //  j = 도착 노드
            for (int j = 0; j < arrSize; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    //  결과를 출력합니다.
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize; j++)
        {
            printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    floydWarshall();
    return 0;
}
