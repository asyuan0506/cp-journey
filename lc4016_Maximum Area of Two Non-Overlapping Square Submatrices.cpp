class Solution {
public:

    int maxArea(vector<vector<int>>& mat) {
        // const int n = mat.size(), m = mat[0].size();
        // int left = 1, right = min(n, m);
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        // dp[0][0] = mat[0][0];
        // for (int i = 1; i < n; i++)
        //     dp[i][0] = mat[i][0];
        // for (int i = 1; i < m; i++)
        //     dp[0][i] = mat[0][i];

        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 1; j < m; j++)
        //     {
        //         if (mat[i][j] == 0) continue;
        //         dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        //     }
        // }

        // auto check = [&](int k) -> bool {
        //     vector<bool> row(n, false);
        //     vector<bool> col(m, false);
        //     for (int i = 0; i < n; i++)
        //     {
        //         for (int j = 0; j < m; j++)
        //         {
        //             if (dp[i][j] >= k)
        //             {
        //                 row[i] = true;
        //                 col[j] = true;
        //             }
        //         }
        //     }

        //     bool has_pre = false;
        //     for (int i = k; i < n; i++) // Vertically
        //     {
        //         has_pre |= row[i - k];
        //         if (row[i] && has_pre)
        //             return true;
        //     }
        //     has_pre = false;
        //     for (int i = k; i < m; i++) // Horizontally
        //     {
        //         has_pre |= col[i - k];
        //         if (col[i] && has_pre)
        //             return true;
        //     }
        //     return false;
        // };
        
        // int ans = 0;
        // while (left <= right)
        // {
        //     int mid = (left + right) / 2;
        //     if (check(mid))
        //     {
        //         ans = mid;
        //         left = mid + 1;
        //     }
        //     else
        //         right = mid - 1;
        // }
        // return ans * ans;


        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i + 1][j + 1] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j] + mat[i][j];
            }
        }

        const int mx = min(n, m);
        vector<vector<pair<int, int>>> v(mx + 1); // max valid side
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 1; i + k <= n && j + k <= m; k++)
                {
                    int sum = prefix[i + k][j + k] - prefix[i][j + k] - prefix[i + k][j] + prefix[i][j];
                    if (sum == k * k)
                        v[k].push_back({i, j});
                    else
                        break;
                }
            }
        }

        for (int k = mx; k >= 1; k--)
        {
            int min_row = n, max_row = -1, min_col = m, max_col = -1;
            for (auto [r, c] : v[k])
            {
                min_row = min(min_row, r);
                max_row = max(max_row, r);
                min_col = min(min_col, c);
                max_col = max(max_col, c);
                if (max_col - min_col >= k || max_row - min_row >= k)
                    return k * k;
            }
        }
        return 0;
    }
};