#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to;
    int weight;
};

int s, t, k;
bool BFS(vector<vector<edge>> &edges, vector<int> &dis, vector<int> &visited)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // first: dis, second: idx, ascending
    pq.push({0, s});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int length = pq.top().first;
        pq.pop();
        if (visited[cur] > k)
            continue;
        visited[cur]++;
        if (cur == t)
        {
            dis.push_back(length);
            if (dis.size() >= k) return true;
        }
        for (int i = 0; i < edges[cur].size(); i++)
        {
            pq.push({length + edges[cur][i].weight, edges[cur][i].to});
        }
    }
    return false;
}

int main()
{
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        
        cin >> s >> t >> k;
        vector<vector<edge>> edges(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, weight;
            cin >> u >> v >> weight;
            edges[u].push_back({ v, weight });
        }
        vector<int> dis;
        vector<int> visited(n + 1, 0);
        if (BFS(edges, dis, visited))
            cout << dis[k - 1] << "\n";
        else
            cout << "-1\n";
    }


    return 0;
}