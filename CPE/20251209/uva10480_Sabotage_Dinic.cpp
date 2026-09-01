#include <bits/stdc++.h>

using namespace std;

int s = 0, t = 1;
vector<int> level;

struct edge
{
    int to;
    long long cap;
    int rev; // Index at edges[to]
};

vector<vector<edge>> edges; // Adjacency list

void add_edge(int u, int v, long long cap)
{
    edges[u].push_back({ v, cap, (int)edges[v].size()});
    edges[v].push_back({ u, cap, (int)edges[u].size() - 1});
}

bool BFS()
{
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (edge &e : edges[cur])
        {
            if (e.cap > 0 && level[e.to] == -1)
            {
                level[e.to] = level[cur] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] != -1;
}

long long DFS(int cur, long long now_cap)
{
    if (cur == t)
        return now_cap;
    long long flow = 0;
    for (edge &e : edges[cur])
    {
        if (level[e.to] == level[cur] + 1 && e.cap > 0)
        {
            long long new_cap = DFS(e.to, min(now_cap, e.cap));
            flow += new_cap;
            now_cap -= new_cap;
            e.cap -= new_cap;
            edges[e.to][e.rev].cap += new_cap;
            if (now_cap == 0)
                return flow;
        } 
    }

    if (flow == 0) // No capacity available at cur, pruning
        level[cur] = -1;

    return flow;
}

int main()
{
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        level.resize(n);
        edges.clear();
        edges.resize(n);
        vector<pair<int, int>> original_edges(m);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            long long cap;
            cin >> a >> b >> cap;
            add_edge(a - 1, b - 1, cap); // 0-index
            original_edges[i] = {a - 1, b - 1};
        }

        int flow = 0;
        while (BFS())
        {
            flow += DFS(s, LLONG_MAX);
        }
        // cout << flow << "\n";
        for (int i = 0; i < m; i++)
        {
            pair<int, int> e = original_edges[i];
            if (level[e.first] >= 0 && level[e.second] >= 0)
                continue;
            else if (level[e.first] == -1 && level[e.second] == -1)
                continue;
            cout << e.first + 1 << " " << e.second + 1 << "\n";
        }
        cout << "\n";
    }

    return 0;
}