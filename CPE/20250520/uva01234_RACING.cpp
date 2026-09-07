#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u, v, w;
};

bool cmp(edge a, edge b)
{
    return a.w > b.w;
}


vector<int> v;
int Find(int a)
{
    return (v[a] <= -1) ? a : v[a] = Find(v[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (v[a] > v[b]) 
        swap(a, b);
    v[a] += v[b];
    v[b] = a;
}

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int n, m;
        cin >> n >> m;
        vector<edge> edges(m);
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            edge e;
            cin >> e.u >> e.v >> e.w;
            edges[i] = e;
            sum += e.w;
        }
        v.assign(n + 1, -1);
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < edges.size(); i++)
        {
            if (Find(edges[i].u) == Find(edges[i].v))
                continue;
            Union(edges[i].u, edges[i].v);
            sum -= edges[i].w;
        }
        cout << sum << "\n";
    }
    cin >> c; // 0

    return 0;
}