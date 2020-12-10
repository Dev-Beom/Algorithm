#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 256
class AdjMatGraph
{
protected:
    int size;
    int vertices[MAX];
    int adj[MAX][MAX]; //정적으로 할당함.

public:
    AdjMatGraph() { reset(); }
    int getVertex(int i) { return vertices[i]; }
    int getEdge(int i, int j) { return adj[i][j]; }
    void setEdge(int i, int j, int val) { adj[i][j] = val; }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size >= MAX; }

    void reset()
    {
        size = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                setEdge(i, j, 0);
            }
        }
    }

    void insertVertex(int value)
    {
        if (isFull() != true)
            vertices[size++] = value;
        else
            cout << "Error: 그래프 점점 개수 초가" << endl;
    }

    void insertEdge(int u, int v, int cal)
    {
        setEdge(u, v, cal);
        setEdge(v, u, cal);
    }

    void display(FILE *fp = stdout)
    { //Vertex 을 2차원 배열 형태로 출력해줌

        fprintf(fp, "%d\n", size);     //문자열 %d에 size 저장 후 출력
        for (int i = 0; i < size; i++) // 가로줄 한줄 씩 출력하는 반복문
        {
            fprintf(fp, "%d ", getVertex(i)); // A,B,C,D 가 출력되는 부분
            for (int j = 0; j < size; j++)
            {
                fprintf(fp, "%3d", getEdge(i, j)); // 실질적으로 값이 출력 되는 부분
            }
            fprintf(fp, "\n");
        }
    }
};

class SrchANGraph : public AdjMatGraph
{
    bool visited[MAX];
    int check;
    int sum;

public:
    void resetVisited()
    {
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
            check = 0;
            sum = 0;
        }
    }
    bool isLinked(int u, int v)
    {
        if (getEdge(u, v) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        // 연결이 되어 있냐고 물어봄
        //연결이 되어있으면 1리턴
    }
    void DFS(int v)
    {
        visited[v] = true;

        cout << getVertex(v) << " ";

        for (int w = 0; w < size; w++)
        {
            if (isLinked(v, w) && visited[w] == false)
            {
                DFS(w);
            }
        }
    }

    void getresult()
    {
        cout << "결과는" << sum << endl;
    }

    void DFS_Calulator(int v)
    {
        visited[v] = true;
        if (check == 0)
        {
            sum = getVertex(v);
            check++;
        }

        for (int w = 0; w < size; w++)
        {
            if (isLinked(v, w) == true && visited[w] == false)
            {
                if (getEdge(v, w) == 1)
                {
                    sum += getVertex(w);
                }
                else if (getEdge(v, w) == 2)
                {
                    sum *= getVertex(w);
                }
                else
                {
                    sum -= getVertex(w);
                }
                DFS_Calulator(w);
            }
        }
    }
};

int main()
{
    SrchANGraph g;
    for (int i = 0; i < 4; i++)
    {
        g.insertVertex(rand() % 10);
    }

    g.insertEdge(0, 1, 2); // 1 더하기 2 빼기 3 곱하기
    g.insertEdge(0, 3, 3);
    g.insertEdge(1, 3, 1);
    g.insertEdge(2, 3, 2);

    cout << "인접 행렬로 표현한 그래프" << endl;
    g.display();

    cout << endl;

    g.resetVisited();
    g.DFS(0);
    
    g.resetVisited();

    g.DFS_Calulator(0);
    g.getresult();
    
    return 0;
}