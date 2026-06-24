#include <bits/stdc++.h>

using namespace std;

void helper(int &i, int &j, vector<vector<int>> &grid)
{
    // top
    if (i - 1 >= 0 && grid[i - 1][j] != -1)
        grid[i][j] = grid[i - 1][j];
    // left
    if (j - 1 >= 0 && grid[i][j - 1] != -1)
        grid[i][j] += grid[i][j - 1];
}

int main()
{
    int w, h;
    while (cin >> w >> h && (w != 0 || h != 0))
    {
        vector<vector<int>> grid(++h, vector<int> (++w, 0));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            grid[y][x] = -1;
        }
        for (int i = 0; i < h; i++)
            if (grid[i][0] == -1)
                break;
            else
                grid[i][0] = 1;
        for (int j = 0; j < w; j++)
            if (grid[0][j] == -1)
                break;
            else
                grid[0][j] = 1;
        for (int i = 1; i < h; i++)
        {
            for (int j = 1; j < w; j++)
            {
                if (grid[i][j] == -1)
                    continue;
                helper(i, j, grid);
            }  
        }
        if (grid[h - 1][w - 1] <= 0)
            cout << "There is no path.\n";
        else if (grid[h - 1][w - 1] == 1)
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
        else
            cout << "There are " << grid[h - 1][w - 1] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
    }

    return 0;
}