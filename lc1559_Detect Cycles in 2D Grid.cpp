// constexpr int dir_r[4] = { -1, 1,  0, 0};
// constexpr int dir_c[4] = {  0, 0, -1, 1};
// class Solution {
// public:
//     bool dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid, int last_r, int last_c)
//     {
//         // If next position isn't visited && not last position -> cycle
//         for (int i = 0; i < 4; i++)
//         {
//             visited[r][c] = true; // Label here it's ok, because if visit again -> cycle
//             int nxt_r = r + dir_r[i];
//             int nxt_c = c + dir_c[i];
//             if (nxt_r < 0 || nxt_c < 0 || nxt_r >= grid.size() || nxt_c >= grid[0].size() || 
//                 (nxt_r == last_r && nxt_c == last_c)) 
//                 continue;
//             if (grid[nxt_r][nxt_c] == grid[r][c])
//             {         
//                 if (visited[nxt_r][nxt_c] || dfs(nxt_r, nxt_c, visited, grid, r, c))
//                     return true;
//             }
//         }
//         return false;
//     }
//     bool containsCycle(vector<vector<char>>& grid) {
//         vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        
//         for (int i = 0; i < grid.size(); i++)
//             for (int j = 0; j < grid[0].size(); j++)
//                 if (!visited[i][j] && dfs(i, j, visited, grid, i, j))
//                     return true;
//         return false;   
//     }

//     bool containsCycle(vector<vector<char>>& grid) {
//         vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        
//         for (int i = 0; i < grid.size(); i++)
//             for (int j = 0; j < grid[0].size(); j++)
//                 if (!visited[i][j] && dfs(i, j, visited, grid, i, j))
//                     return true;
//         return false;   
//     }
// };

vector<int> p;

int Find(int a)
{
    if (p[a] < 0) return a;
    p[a] = Find(p[a]);
    return p[a];
}

bool Union(int a, int b)
{
    int parent_a = Find(a);
    int parent_b = Find(b);
    if (parent_a == parent_b) return true;

    p[parent_a] += p[parent_b];
    p[parent_b] = parent_a;
    return false;
}

class Solution {
public:

    bool containsCycle(vector<vector<char>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        const int n = rows * cols;
        p.assign(n, -1);

        // From left to right, top to bottom, every node only need to check left and up direction 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j]) // Check up direction, if same: union
                    Union((i - 1) * cols + j, i * cols + j);
                if (j - 1 >= 0 && grid[i][j - 1] == grid[i][j]) // Check left direction, if same & parent same -> Cycle
                    if (Union(i * cols + j - 1, i * cols + j))
                        return true;
            }
        }
        return false;   
    }
};