#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;

int in(int a)
{
    return 2 * a;
}
int out(int a)
{
    return 2 * a + 1;
}

int bfs(int s, int t, vector<vector<int>> &capacity, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({ s, INT_MAX });
    while (!q.empty())
    {
        int cur = q.front().first;
        int cap = q.front().second;
        q.pop();

        for (int i = 0; i < capacity[cur].size(); i++)
        {
            if (capacity[cur][i] != 0 && parent[i] == -1)
            {
                parent[i] = cur;
                int nxt_cap = min(cap, capacity[cur][i]);
                if (i == t) return nxt_cap;
                q.push({ i, nxt_cap });
            }
        }
    }

    return 0;
}

int EdmondsKarp(int s, int t, vector<vector<int>> capacity)
{  
    vector<int> parent(capacity.size());
    int flow = 0;
    int new_flow;
    while (new_flow = bfs(s, t, capacity, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}


int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n >= 2 && m == 0)
        {
            cout << "0\n";
            continue;
        }
        vector<vector<int>> capacity(2 * n, vector<int> (2 * n, 0));
        for (int i = 0; i < n; i++)
        {
            capacity[in(i)][out(i)] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            char buffer;
            int a, b;
            cin >> buffer >> a >> buffer >> b >> buffer;
            capacity[out(a)][in(b)] = INF;
            capacity[out(b)][in(a)] = INF;
        }
        int ans = n;
        for (int s = 0; s < n; s++)
        {
            for (int t = s + 1; t < n; t++)
            {
                if (capacity[out(s)][in(t)] == INF) // Direct connection, no need to check
                    continue;
                ans = min(ans, EdmondsKarp(out(s), in(t), capacity));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}