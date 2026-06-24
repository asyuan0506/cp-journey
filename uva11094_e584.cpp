#include <bits/stdc++.h>

using namespace std;

void helper(int r, int c, vector<vector<char>> &m, int &cnt, char &land)
{
    if (m[r][c] != land)
        return;
    ++cnt;
    m[r][c] = '\0'; // Two letters may include special char
    if (r + 1 < m.size())
        helper(r + 1, c, m, cnt, land);
    if (r - 1 >= 0)
        helper(r - 1, c, m, cnt, land);
    if (c + 1 < m[0].size())
        helper(r, c + 1, m, cnt, land);
    else if (c + 1 == m[0].size())
        helper(r, 0, m, cnt, land);
    if (c - 1 >= 0)
        helper(r, c - 1, m, cnt, land);
    else if (c - 1 < 0)
        helper(r, m[0].size() - 1, m, cnt, land);
}

int main()
{
    int rows, cols;
    while (cin >> rows >> cols && rows + cols)
    {
        vector<vector<char>> m(rows, vector<char> (cols));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> m[i][j];
        int r, c;
        cin >> r >> c;
        char land = m[r][c];
        int max_cnt = 0;
        helper(r, c, m, max_cnt, land);
        max_cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (m[i][j] != land)
                    continue;
                int tmp = 0;
                helper(i, j, m, tmp, land);
                max_cnt = max(max_cnt, tmp);
            }
        }

        cout << max_cnt << "\n";
    }
    
    return 0;
}