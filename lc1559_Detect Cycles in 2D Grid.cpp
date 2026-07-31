constexpr int dir_r[4] = { -1, 1,  0, 0};
constexpr int dir_c[4] = {  0, 0, -1, 1};
class Solution {
public:
    bool dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid, int last_r, int last_c)
    {
        // If next position isn't visited && not last position -> cycle
        for (int i = 0; i < 4; i++)
        {
            int nxt_r = r + dir_r[i];
            int nxt_c = c + dir_c[i];
            if (nxt_r < 0 || nxt_c < 0 || nxt_r >= grid.size() || nxt_c >= grid[0].size() || 
                (nxt_r == last_r && nxt_c == last_c)) 
                continue;
            if (grid[nxt_r][nxt_c] == grid[r][c])
            {
                if (visited[nxt_r][nxt_c])
                    return true;
                
                visited[nxt_r][nxt_c] = true;
                if (dfs(nxt_r, nxt_c, visited, grid, r, c))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j])
                {
                    visited[i][j] = true;
                    if (dfs(i, j, visited, grid, i, j)) return true;
                }
            }
        }
        return false;   
    }
};