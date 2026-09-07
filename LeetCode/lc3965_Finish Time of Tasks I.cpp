class Solution {
public:
    // long long solve(int idx, vector<vector<int>>& tree, vector<int>& baseTime) {
    //     if (tree[idx].empty())
    //         return baseTime[idx];
    //     long long earliest = LLONG_MAX, latest = LLONG_MIN;
    //     for (int child : tree[idx]) {
    //         long long time = solve(child, tree, baseTime);
    //         earliest = min(earliest, time);
    //         latest = max(latest, time);
    //     }
    //     return baseTime[idx] - earliest + 2 * latest; // latest + (latest - earliest) + baseTime[idx], maybe overflow

    // }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> tree(n);
        for (vector<int>& edge : edges)
            tree[edge[0]].push_back(edge[1]);
        
        auto solve = [&](this auto& self, int idx) -> long long {
            if (tree[idx].empty())
                return baseTime[idx];
            long long earliest = LLONG_MAX, latest = LLONG_MIN;
            for (int child : tree[idx]) {
                long long time = self(child);
                earliest = min(earliest, time);
                latest = max(latest, time);
            }
            return latest - earliest + latest + baseTime[idx]; // latest + (latest - earliest) + baseTime[idx]
        };

        return solve(0);
    }
};