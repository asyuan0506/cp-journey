#include <bits/stdc++.h>

using namespace std;

void DFS(int r, int c, vector<vector<char>> &m, char target)
{
    if (r < 0 || c < 0 || r >= m.size() || c >= m[0].size() || m[r][c] != target)
        return;
    m[r][c] = '-';
    DFS(r - 1, c, m, target);
    DFS(r + 1, c, m, target);
    DFS(r, c - 1, m, target);
    DFS(r, c + 1, m, target);
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N;
    int Case = 0;
    while (N--)
    {
        cin >> r >> c;
        vector<vector<char>> m(r, vector<char>(c));
        vector<pair<int, int>> cnt(26, make_pair('z', 0));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                char tmp;
                cin >> tmp;
                m[i][j] = tmp;
                cnt[tmp - 'a'].first = tmp ;
            }

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (m[i][j] != '-')
                {
                    cnt[m[i][j] - 'a'].second++;
                    DFS(i, j, m, m[i][j]);
                }
        sort(cnt.begin(), cnt.end(), cmp);
        cout << "World #" << ++Case << "\n";
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i].second == 0)
                break;
            cout << (char)cnt[i].first << ": " << cnt[i].second << "\n";
        }
    }

    return 0;
}