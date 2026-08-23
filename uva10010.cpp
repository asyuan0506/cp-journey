#include <bits/stdc++.h>

using namespace std;

const int dir_r[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dir_c[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool dfs(int r, int c, vector<vector<char>> &mp, string &s, int idx, int dir)
{
    if (r < 0 || c < 0 || r >= mp.size() || c >= mp[0].size())
        return false;
    if (mp[r][c] != s[idx])
        return false;
    if (s.length() == idx + 1)
        return true;

    return dfs(r + dir_r[dir], c + dir_c[dir], mp, s, idx + 1, dir);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool first = true;
    int N;
    cin >> N;
    while (N--)
    {
        if (!first)
            cout << "\n";
        first = false;

        int rows, cols;
        cin >> rows >> cols;
        vector<vector<char>> mp(rows, vector<char>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] >= 'a')
                {
                    mp[i][j] = mp[i][j] - 'a' + 'A';
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] >= 'a')
                    s[i] = s[i] - 'a' + 'A';
            }

            bool found = false;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    for (int dir = 0; dir < 8; dir++)
                    {
                        if (s[0] == mp[i][j] && dfs(i, j, mp, s, 0, dir))
                        {
                            cout << i + 1 << " " << j + 1 << "\n";
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
                if (found)
                    break;
            }
        }
    }

    return 0;
}