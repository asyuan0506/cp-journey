#include <iostream>
#include <vector>

using namespace std;

bool land_out_of_range(int r, int c, int &m, int &n)
{
    if (r < 0 || c < 0 || r >= m || c >= n)
        return true;
    return false;
}

void oil_pocket(int r, int c, vector<vector<char>> &land, int &m, int &n)
{
    if (land_out_of_range(r, c, m, n) || land[r][c] != '@')
        return;
    land[r][c] = 'O';
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            oil_pocket(r + i, c + j, land, m, n);
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
        {
            return 0;
        }
        vector<vector<char>> land(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> land[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == '@')
                {
                    cnt++;
                    oil_pocket(i, j, land, m, n);
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}