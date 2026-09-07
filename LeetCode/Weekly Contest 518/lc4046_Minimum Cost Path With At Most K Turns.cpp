class Solution {
public:
    const int dir_r[4] = { -1, 1, 0, 0};
    const int dir_c[4] = { 0, 0, -1, 1};  
    struct node 
    {
        int r, c, k;
        int cost;
        int last_dir;
    };
    struct cmp
    {
        bool operator() (node a, node b)
        {
            return a.cost > b.cost;
        }
    };
    int minCost(vector<vector<int>>& grid, int k) {
        const int n = grid.size(), m = grid[0].size();
        priority_queue<node, vector<node>, cmp> pq;
        vector<vector<vector<vector<int>>>> visited(n, vector<vector<vector<int>>>(m, vector<vector<int>> (k + 2, vector<int> (4, INT_MAX))));
        for (int i = 0; i <= k; i++)
            for (int j = 0; j < 4; j++)
                visited[0][0][i][j] = grid[0][0];
        pq.push({0, 0, k + 1, grid[0][0], -1});
        while (!pq.empty())
        {
            node cur = pq.top();
            pq.pop();
            if (cur.r == n - 1 && cur.c == m - 1)
                return cur.cost;
            for (int i = 0; i < 4; i++)
            {
                int nxt_r = cur.r + dir_r[i];
                int nxt_c = cur.c + dir_c[i];
                if (nxt_r < 0 || nxt_c < 0 || nxt_r >= n || nxt_c >= m)
                    continue;
                if (i != cur.last_dir)
                {
                    if (cur.k == 0)
                        continue;
                    node tmp = {nxt_r, nxt_c, cur.k - 1, cur.cost + grid[nxt_r][nxt_c], i};
                    if (tmp.cost < visited[nxt_r][nxt_c][tmp.k][i])
                    {
                        visited[nxt_r][nxt_c][tmp.k][i] = tmp.cost;
                        pq.push(tmp);
                    }
                }
                else
                {
                    node tmp = {nxt_r, nxt_c, cur.k, cur.cost + grid[nxt_r][nxt_c], i};
                    if (tmp.cost < visited[nxt_r][nxt_c][tmp.k][i])
                    {
                        visited[nxt_r][nxt_c][tmp.k][i] = tmp.cost;
                        pq.push(tmp);
                    }
                }
               
            }
        }
        return -1;
    }
};