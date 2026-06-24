#include <bits/stdc++.h>

using namespace std;

int a[26];          // Parent
vector<int> va[26]; // Parents

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    /* BFS
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<bool>> route(26, vector<bool>(26, 0)); // There are only 26 alphabet
        for (int i = 0; i < m; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            int c1_idx = c1[0] - 'A';
            int c2_idx = c2[0] - 'A';
            route[c1_idx][c2_idx] = true;
            route[c2_idx][c1_idx] = true;
        }
        for (int i = 0; i < n; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            queue<string> nxt; // No cycle so no need visited array
            nxt.push(c1.substr(0, 1));
            while (!nxt.empty())
            {
                string ans = nxt.front();
                int cur = ans[0] - 'A';
                nxt.pop();
                if (cur == c2[0] - 'A')
                {
                    reverse(ans.begin(), ans.end());
                    cout << ans << "\n";
                    break;
                }
                for (int i = 0; i < 26; i++)
                {
                    if (route[cur][i] && i != cur)
                    {
                        nxt.push((char)(i + 'A') + ans);
                    }
                }
            }
        }
        if (t != 0)
            cout << "\n";
    }
    */

    int t, m, n, c1, c2;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        memset(a, -1, sizeof(a));
        for (int i = 0; i < 26; i++)
            va[i].clear();
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            c1 = s1[0] - 'A';
            c2 = s2[0] - 'A';
            a[c2] = c1;
        }
        int cur;
        for (int i = 0; i < 26; i++)
        {
            cur = i;
            va[i].push_back(cur);
            while (a[cur] != -1)
            {
                va[i].push_back(a[cur]);
                cur = a[cur];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            c1 = s1[0] - 'A';
            c2 = s2[0] - 'A';
            int root = -1; // Closest common ancestor
            for (int j : va[c1])
            {
                for (int k : va[c2])
                {
                    if (j == k)
                    {
                        root = k;
                        break;
                    }
                }
                if (root == j)
                    break;
            }
            for (int j = 0; va[c1][j] != root; j++)
            {
                cout << (char)(va[c1][j] + 'A');
            }
            bool flag = false;
            for (int j = va[c2].size() - 1; j >= 0; j--)
            {
                if (va[c2][j] == root)
                    flag = true;
                if (flag)
                    cout << (char)(va[c2][j] + 'A');
            }
            cout << "\n";
        }

        if (t != 0)
            cout << "\n";
    }

    return 0;
}