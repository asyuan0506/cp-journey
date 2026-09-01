#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> capacity;
vector<vector<int>> edges;

int bfs(int s, int t, vector<int>& visited)
{
    visited[s] = -2;
    queue<pair<int, int>> q;
    
    q.push({ s, INT_MAX });
    while (!q.empty())
    {
        int cur = q.front().first;
        long long cap = q.front().second;
        q.pop();

        for (int i = 1; i < capacity[cur].size(); i++)
        {
            if (capacity[cur][i] == 0) continue;
            if (visited[i] == -1)
            {
                visited[i] = cur;
                long long nxt_cap = min(cap, capacity[cur][i]);
                if (i == t)
                {
                    return nxt_cap;
                }

                q.push({ i, nxt_cap });
            }
        }
    }
    return 0;
}

void dfs(int s, vector<int> &visited)
{
    for (int i = 1; i < capacity[s].size(); i++)
    {
        if (capacity[s][i] != 0 && !visited[i])
        {
            visited[i] = true;
            dfs(i, visited);
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        capacity.assign(n + 1, vector<long long> (n + 1, 0));
        edges.clear();
        edges.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, cap;
            cin >> a >> b >> cap;
            capacity[a][b] = cap;
            capacity[b][a] = cap;

            edges[a].push_back(b);
        }
        int s = 1, t = 2;
        long long flow = 0;
        long long new_flow;
        vector<int> visited(n + 1, -1);
        while (new_flow = bfs(s, t, visited))
        {
            flow += new_flow;
            int cur = t;
            while (cur != s)
            {
                int prev = visited[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;

                cur = prev;
            }

            visited.assign(n + 1, -1);
        }
        // cout << flow << "\n";
        visited.assign(n + 1, 0);
        visited[s] = true;
        dfs(s, visited);
        for (int i = 1; i <= n; i++)
        {
            for (int j : edges[i])
                if (visited[i] != visited[j])
                    cout << i << " " << j << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}