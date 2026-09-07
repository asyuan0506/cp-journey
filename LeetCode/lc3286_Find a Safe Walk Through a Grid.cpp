const int dir_r[4] = { -1, 1,  0, 0};
const int dir_c[4] = {  0, 0, -1, 1};

class Solution {
public:
    struct pt 
    {
        int r;
        int c;
        int h;
    };
    struct cmp 
    {
        bool operator()(pt a, pt b)
        {
            return a.h < b.h; // Decreasing
        }
    };
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0]) health--;
        if (!health) return false;
        grid[0][0] = 2;
        
        priority_queue<pt, vector<pt>, cmp> pq; // Greedy: Choose the highest health way
        pq.push({0, 0, health});
        while (!pq.empty())
        {
            auto [r, c, h] = pq.top();
            pq.pop();
            if (r == grid.size() - 1 && c == grid[0].size() - 1 && h)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int nx_r = r + dir_r[i];
                int nx_c = c + dir_c[i];
                if (nx_r < 0 || nx_c < 0 || nx_r >= grid.size() || nx_c >= grid[0].size())
                    continue;
                int unsafe = grid[nx_r][nx_c];
                if (unsafe >= 2 || (unsafe && h == 1))
                    continue;
                grid[nx_r][nx_c] = 2; // Visited
                pq.push({nx_r, nx_c, h - unsafe});
            }
        }        
        return false;
    }
};