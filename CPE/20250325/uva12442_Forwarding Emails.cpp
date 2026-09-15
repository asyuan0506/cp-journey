#include <bits/stdc++.h>

using namespace std;

vector<int> edges;
vector<int> mx;
vector<int> state; // 0: unvisited, 1: visiting, 2: visited

int DFS(int u)
{
    if (state[u] == 2)
        return mx[u];

    state[u] = 1;
    int nxt = edges[u];
    if (state[nxt] == 0)
    {
        DFS(nxt);
    }
    else if (state[nxt] == 1)
    {
        // Found a cycle, count the size of the cycle
        int cycle_size = 1;
        int cur = u;
        do
        {
            cycle_size++;
            cur = edges[cur];
        } while (cur != u);
        // Mark all nodes in the cycle with the cycle size
        cur = u;
        do
        {
            mx[cur] = cycle_size;
            state[cur] = 2;
            cur = edges[cur];
        } while (cur != u);
    }
    if (state[u] != 2)
    {
        mx[u] = 1 + mx[nxt];
        state[u] = 2;
    }
    return mx[u];
}
int main()
{
    int N;
    cin >> N;
    int Case = 0;
    while (N--)
    {
        int n;
        cin >> n;
        edges.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            edges[u] = v; // Only one directed edge
        }
        mx.assign(n + 1, 0);
        state.assign(n + 1, 0);
        
        int mx_idx = 1;
        for (int i = 1; i <= n; i++)
        {
            int res = DFS(i);
            if (res > mx[mx_idx])
                mx_idx = i;
        }

        cout << "Case " << ++Case << ": " << mx_idx << "\n";
    }

    return 0;
}