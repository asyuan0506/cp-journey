#include <bits/stdc++.h>

using namespace std;

struct pt
{
    int l, r, c;
    int t;
    pt(int l, int r, int c, int t) : l(l), r(r), c(c), t(t) {};
    pt() : l(-1), r(-1), c(-1), t(0) {};
};
int L, R, C;
vector<vector<vector<char>>> m(31, vector<vector<char>> (31, vector<char> (31, '#')));
int dir_l[6] = { 1, -1,  0, 0, 0,  0};       // U D N S W E
int dir_r[6] = { 0,  0, -1, 1, 0,  0};       // U D N S W E
int dir_c[6] = { 0,  0,  0, 0, -1, 1};       // U D N S W E
pt S;

int bfs()
{
    queue<pt> q;
    q.push(S);
    while (!q.empty())
    {
        auto n = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nl = n.l + dir_l[i];
            int nr = n.r + dir_r[i];
            int nc = n.c + dir_c[i];
            if (nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C)
                continue;
            if (m[nl][nr][nc] == '#' || m[nl][nr][nc] == 'V')
                continue;
            if (m[nl][nr][nc] == 'E')
                return n.t + 1;
            pt tmp(nl, nr, nc, n.t + 1);
            m[nl][nr][nc] = 'V';
            q.push(tmp);
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> L >> R >> C && L || R || C)
    {
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    char tmp;
                    cin >> tmp;
                    m[i][j][k] = tmp;
                    if (tmp == 'S')
                    {
                        S.l = i; S.r = j; S.c = k; S.t = 0;
                    }
                }
            }
        }
        int ans = bfs();
        if (ans == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << ans << " minute(s).\n";
    }

    return 0;
}