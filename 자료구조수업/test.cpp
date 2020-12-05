#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000 + 1;

int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx)

{
    cout << idx << " ";
    for (int i = 1; i <= N; i++)
    {
        if (adjacent[idx][i] && !visited[i])
        {
            visited[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int idx)
{
    q.push(idx);
    visited[idx] = 1;

    while (!q.empty())
    {
        idx = q.front();
        q.pop();
        cout << idx << " ";
        //BFS는 해당 노드에 인접한 노드들을 모두 추가한 뒤 BFS 진행
        for (int i = 1; i <= N; i++)
            if (adjacent[idx][i] && !visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
    }
}

int main()
{
    cout << "dd";
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        adjacent[from][to] = 1;
        adjacent[to][from] = 1;
    }
    visited[V] = 1; //V에서 시작하므로
    DFS(V);
    cout << endl;
    memset(visited, false, sizeof(visited));
    BFS(V);
    cout << endl;

    return 0;
}