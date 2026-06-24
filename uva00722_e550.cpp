#include <bits/stdc++.h>

using namespace std;

void water_area(int r, int c, vector<vector<bool>> &space, int &cnt)
{
    if (r < 0 || c < 0 || r >= space.size() || c >= space[0].size() || space[r][c] == 1)
        return;

    cnt++;
    space[r][c] = 1;
    water_area(r - 1, c, space, cnt);
    water_area(r + 1, c, space, cnt);
    water_area(r, c - 1, space, cnt);
    water_area(r, c + 1, space, cnt);
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    int T;
    ss >> T;
    getline(cin, s); // blank

    while (T--)
    {
        getline(cin, s);
        int w_r, w_c;
        ss.clear();
        ss.str(s);
        ss >> w_r >> w_c;
        w_r--;
        w_c--;

        vector<vector<bool>> space;
        while (getline(cin, s) && !s.empty())
        {
            vector<bool> tmp;
            for (char c : s)
                tmp.push_back(c - '0');
            space.push_back(tmp);
        }

        int cnt = 0;
        water_area(w_r, w_c, space, cnt);
        cout << cnt << endl;
    }
    return 0;
}