#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;

int in(int num)
{
    return 2 * num;
}
int out(int num)
{
    return 2 * num + 1;
}

struct edge {
    int to;
    int cap;
    int rev; // Index at edges[to]
};

vector<vector<edge>> edges;
vector<vector<edge>> edges_copy;

void add_edge(int u, int v, int cap)
{
    edges[out(u)].push_back({ in(v), cap, (int)edges[in(v)].size() });
    edges[in(v)].push_back({ out(u), 0, (int)edges[out(u)].size() - 1});

    edges[out(v)].push_back({ in(u), cap, (int)edges[in(u)].size()});
    edges[in(u)].push_back({ out(v), 0, (int)edges[out(v)].size() - 1});
}

bool BFS(int s, int t, vector<int> &level)
{
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (edge e : edges[cur])
        {
            if (level[e.to] == -1 && e.cap > 0)
            {
                level[e.to] = level[cur] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int DFS(int s, int t, int now_cap, vector<int> &level)
{
    if (s == t)
        return now_cap;

    int flow = 0;
    for (edge &e : edges[s])
    {
        if (level[e.to] == level[s] + 1 && e.cap > 0)
        {
            int new_flow = DFS(e.to, t, min(now_cap, e.cap), level);
            
            now_cap -= new_flow;
            flow += new_flow;
            e.cap -= new_flow;
            edges[e.to][e.rev].cap += new_flow;
            
            if (now_cap == 0)
                break;
        }
    }
    return flow;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        edges.clear();
        edges.resize(2 * n);
        for (int i = 0; i < n; i++)
        {
            edges[in(i)].push_back({out(i), 1, (int)edges[out(i)].size()});
            edges[out(i)].push_back({in(i), 0, (int)edges[in(i)].size() - 1});
        }

        char buffer;
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> buffer >> u >> buffer >> v >> buffer;
            add_edge(u, v, INF);
        }
        edges_copy = edges;

        int ans = n;
        for (int i = 0; i < n; i++)
        {
            edges = edges_copy;
            for (int j = i + 1; j < n; j++)
            {
                edges = edges_copy;
                vector<int> level(2 * n);
                int flow = 0;
                while (BFS(out(i), in(j), level))
                {
                    flow += DFS(out(i), in(j), INT_MAX, level);
                }
                ans = min(ans, flow);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}