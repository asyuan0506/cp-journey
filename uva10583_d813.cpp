#include <bits/stdc++.h>

using namespace std;

void DFS(int t, unordered_map<int, vector<int>> &same_map, vector<int> &visited)
{
    if (visited[t])
        return;
    visited[t] = true;
    for (int i : same_map[t])
        DFS(i, same_map, visited);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int Case = 0;
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        unordered_map<int, vector<int>> same_map;
        vector<int> visited(n + 1, false);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (same_map.find(a) == same_map.end())
                same_map[a] = vector<int> (1, b);
            else
                same_map[a].push_back(b);
            if (same_map.find(b) == same_map.end())
                same_map[b] = vector<int> (1, a);
            else
                same_map[b].push_back(a);
        }
        int num = n;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                num--;
            if (same_map.find(i) == same_map.end())
            {
                // visited[i] = true; // Actually not used
                continue;
            }
            DFS(i, same_map, visited);
        }
        cout << "Case " << ++Case << ": " << num << "\n";
    }

    return 0;
}