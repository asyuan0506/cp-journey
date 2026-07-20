class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> ans(rows, vector<int> (cols));
        int idx = k; // 2D -> 1D
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int r = idx / cols % rows;
                int c = idx % cols;
                ans[r][c] = grid[i][j];
                idx++;
            }
        }
        return ans;
    }
};