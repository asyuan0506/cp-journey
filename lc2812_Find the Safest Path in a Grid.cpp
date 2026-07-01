static const int dir_r[4] = { -1, 1,  0, 0};
static const int dir_c[4] = {  0, 0, -1, 1};
class Solution {   
public:
    struct point {
        int r;
        int c;
        int d;
        point(int r, int c, int d) : r(r), c(c), d(d) {};
    };
    struct cmp {
        bool operator()(point a, point b) {
            return a.d < b.d;
        }
    };
    static bool out(int &r, int &c, vector<vector<int>> &v)
    {
        return (r < 0 || c < 0 || r >= v.size() || c >= v[0].size());
    }
    void minDistance(vector<vector<int>> &grid, vector<vector<int>> &min_dis)
    {
        queue<point> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push(point(i, j, 0));
                    min_dis[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            point pt = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx_r = pt.r + dir_r[i];
                int nx_c = pt.c + dir_c[i];
                if (out(nx_r, nx_c, grid) || pt.d + 1 >= min_dis[nx_r][nx_c])
                    continue;
                q.push(point(nx_r, nx_c, pt.d + 1));
                min_dis[nx_r][nx_c] = pt.d + 1;
            }
        }
    }
    static int safestPath(vector<vector<int>> &min_dis, vector<vector<bool>> &visited)
    {
        priority_queue<point, vector<point>, cmp> nx;
        point f(0, 0, min_dis[0][0]);
        nx.push(f);
        visited[0][0] = true;
        int mx = min_dis[0][0];
        while (!nx.empty())
        {
            point pt = nx.top();
            nx.pop();
            mx = min(mx, min_dis[pt.r][pt.c]); // Update here when using 1 variable mx, or store path in pt.d
            if (pt.r == min_dis.size() - 1 && pt.c == min_dis[0].size() - 1)
                return mx;
            for (int i = 0; i < 4; i++)
            {
                int tmp_r = pt.r + dir_r[i];
                int tmp_c = pt.c + dir_c[i];
                if (out(tmp_r, tmp_c, min_dis) || visited[tmp_r][tmp_c])
                    continue;
                nx.push(point(tmp_r, tmp_c, min_dis[tmp_r][tmp_c]));
                visited[tmp_r][tmp_c] = true;
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int r = grid.size();
        const int c = grid[0].size();
        vector<vector<int>> min_dis(r, vector<int> (c, INT_MAX));
        minDistance(grid,min_dis);
        vector<vector<bool>> visited(r, vector<bool> (c, false));
        return safestPath(min_dis, visited);
    }
};