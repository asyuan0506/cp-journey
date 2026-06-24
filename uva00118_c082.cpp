#include <bits/stdc++.h>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
char dir_to_c[4] = {'N', 'E', 'S', 'W'};

bool foward(int &x, int &y, int dir, vector<vector<bool>> &land)
{
    int next_x = x + dir_x[dir];
    int next_y = y + dir_y[dir];
    if (next_x < 0 || next_y < 0 || next_x >= land[0].size() || next_y >= land.size())
    {
        if (land[y][x])   // if scent at that place
            return false; // ignore
        land[y][x] = true;
        return true;
    }
    x = next_x;
    y = next_y;
    return false;
}

int main()
{
    int l, w;
    cin >> l >> w;
    vector<vector<bool>> land(w + 1, vector<bool>(l + 1, 0));
    int x, y, dir;
    char dir_c;
    bool lost = false;
    while (cin >> x >> y >> dir_c)
    {
        if (dir_c == 'N')
            dir = 0;
        else if (dir_c == 'E')
            dir = 1;
        else if (dir_c == 'S')
            dir = 2;
        else if (dir_c == 'W')
            dir = 3;

        string operation;
        cin >> operation;
        for (char c : operation)
        {
            if (c == 'L')
                dir = (dir - 1 + 4) % 4;
            else if (c == 'R')
                dir = (dir + 1) % 4;
            else if (c == 'F')
            {
                lost = foward(x, y, dir, land);
                if (lost)
                    break;
            }
        }
        cout << x << " " << y << " " << dir_to_c[dir];
        if (lost)
            cout << " LOST";
        cout << "\n";
    }

    return 0;
}