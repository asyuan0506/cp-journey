class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; i++)
            sorted_nodes[i] = {nums[i], i};
        sort(sorted_nodes.begin(), sorted_nodes.end());
        
        vector<int> to_sorted(n);
        for (int i = 0; i < n; i++)
            to_sorted[sorted_nodes[i].second] = i;   

        vector<vector<int>> bl(n, vector<int>(18)); // Binary Lifting Table 2^17 = 131072 > 10^5
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            r = max(r, i);
            while (r + 1 < n && sorted_nodes[r + 1].first - sorted_nodes[i].first <= maxDiff)
                r++;
            bl[i][0] = r; // Rightmost can reach in one step(2^0)
        }        
        for (int j = 1; j < 18; j++)
        {
            for (int i = 0; i < n; i++)
            {
                bl[i][j] = bl[bl[i][j - 1]][j - 1];
            }
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int a = to_sorted[queries[i][0]], b = to_sorted[queries[i][1]];
            if (a > b)
                swap(a, b);
            if (a == b)
            {
                ans[i] = 0;
                continue;
            }
            int step = 0;
            for (int j = 17; j >= 0; j--)
            {
                if (bl[a][j] < b && bl[a][j] != a)
                {
                    a = bl[a][j];
                    step += (1 << j);
                }
            }
            if (bl[a][0] >= b)
                ans[i] = step + 1;
            else
                ans[i] = -1;
        }

        return ans;
    }
};