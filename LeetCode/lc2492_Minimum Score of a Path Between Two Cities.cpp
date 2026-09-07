class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (vector<int>& edge : roads)
        {
            int a = edge[0];
            int b = edge[1];
            int dis = edge[2];
            graph[a].push_back({b, dis});
            graph[b].push_back({a, dis});
        }
        vector<bool> visited(n + 1, false);
        stack<int> dfs;
        dfs.push(1);
        visited[1] = true;
        int min_dis = INT_MAX;
        while (!dfs.empty())
        {
            int city = dfs.top();
            dfs.pop();
            for (pair<int, int> &i : graph[city])
            {
                auto [nxt, dis] = i;
                min_dis = min(min_dis, dis);
                if (!visited[nxt])
                {
                    visited[nxt] = true;
                    dfs.push(nxt);
                }
            }
        }
        return min_dis;
    }
};