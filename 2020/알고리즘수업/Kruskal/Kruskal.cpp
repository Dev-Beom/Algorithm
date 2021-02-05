#include <iostream>
#include <algorithm>
#include <vector>

const int n = 7;
const int m = 11;

int getParent(int parent[], int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int find(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class Edge
{
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance)
    {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(Edge &edge) const
    {
        return this->distance < edge.distance;
    }
};

int main()
{

    std::vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));

    // 비용에 따라 먼저 정렬해준다.
    sort(v.begin(), v.end());

    // 그래프 최초 설정 먼저 해준다.
    int set[n];
    for (int i = 0; i < n; i++)
    {
        set[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // 사이클이 발생하지 않을 떄만 합쳐준다.
        if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1))
        {
            sum += v[i].distance;
            unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}