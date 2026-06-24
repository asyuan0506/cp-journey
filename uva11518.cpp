#include <bits/stdc++.h>

using namespace std;

int dfs(vector<bool> &knocked, vector<vector<int>> &tiles, int knock)
{
    if (knocked[knock] == true)
        return 0;
    int cnt = 1;
    knocked[knock] = true;
    for (int j : tiles[knock])
    {
        cnt += dfs(knocked, tiles, j);
    }
    return cnt;
}

int main()
{
    int CASE;
    cin >> CASE;
    while (CASE--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> tiles(n + 1);
        vector<bool> knocked(n + 1, false);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            tiles[a].push_back(b);
        }
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            int tmp;
            cin >> tmp;
            ans += dfs(knocked, tiles, tmp);
        }
        cout << ans << "\n";
    }

    return 0;
}