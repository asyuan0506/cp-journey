const int dir_r[3] = {  1, 1, 0};
const int dir_c[3] = {  0, 1, 1};
const int MOD = 1000000000 + 7;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int n = board.size();
        vector<vector<pair<int, int>>> grid(n, vector<pair<int, int>>(n, {0, 0})); // first: max score, second: methods
        grid[n - 1][n - 1] = {0, 1};
        for (int i = n - 2; i >= 0; i--)
        {
            if (board[n - 1][i] == 'X')
                break;
            grid[n - 1][i] = { grid[n - 1][i + 1].first + (board[n - 1][i] - '0'), 1};
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (board[i][n - 1] == 'X')
                break;
            grid[i][n - 1] = { grid[i + 1][n - 1].first + (board[i][n - 1] - '0'), 1};
        }
        board[0][0] = '0';
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (board[i][j] == 'X') continue;
                for (int k = 0; k < 3; k++)
                {
                    int r = i + dir_r[k], c = j + dir_c[k];
                    if (grid[r][c].second == 0)
                        continue;
                    int sum = grid[r][c].first + (board[i][j] - '0');
                    if (sum > grid[i][j].first)
                        grid[i][j] = {sum, grid[r][c].second} ;
                    else if (sum == grid[i][j].first)
                        grid[i][j].second = (grid[i][j].second + grid[r][c].second) % MOD;
                }
            }
        }
        vector<int> ans(2);
        ans[0] = grid[0][0].first;
        ans[1] = grid[0][0].second;
        return ans;
    }
};