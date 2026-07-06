class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        const int n = online.size();
        int l = INT_MAX, r = 0;
        vector<vector<pair<int, long long>>> my_map(n);
        for (vector<int> i : edges)
        {
            if (!online[i[0]] || !online[i[1]])
                continue;
            my_map[i[0]].push_back({i[1], i[2]});
            l = min(l, i[2]);
            r = max(r, i[2]);
        }

        auto check = [&](int mid) -> bool
        {
            vector<long long> dis(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // dijkstra first: accumulated cost, second: next node
            pq.push({0, 0});
            while (!pq.empty())
            {
                pair<long long, int> node = pq.top();
                pq.pop();
                if (node.first > k)
                    return false;
                if (node.second == n - 1)
                    return true;
                if (node.first > dis[node.second])
                    continue;
                for (pair<int, long long> &i : my_map[node.second])
                {
                    if (i.second < mid)
                        continue;
                    long long cost = node.first + i.second;
                    if (cost < dis[i.first])
                    {
                        dis[i.first] = cost;
                        pq.push({cost, i.first});
                    }
                }
            }
            return false;
        };

        if (!check(l))
            return -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};

// class Solution {
// public:
//     int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
//                          long long k) {
//         int n = online.size();
//         vector<vector<pair<int, int>>> g(n);
//         int l = INT_MAX, r = 0;

//         for (auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             int w = edge[2];
//             if (!online[u] || !online[v]) {
//                 continue;
//             }
//             g[u].push_back({v, w});
//             l = min(l, w);
//             r = max(r, w);
//         }

//         auto check = [&](int mid) -> bool {
//             vector<long long> dis(n, LLONG_MAX);
//             priority_queue<pair<long long, int>, vector<pair<long long, int>>,
//                            greater<>>
//                 q;

//             dis[0] = 0;
//             q.push({0, 0});

//             while (!q.empty()) {
//                 auto [d, u] = q.top();
//                 q.pop();

//                 if (d > k) {
//                     return false;
//                 }
//                 if (u == n - 1) {
//                     return true;
//                 }
//                 if (d > dis[u]) {
//                     continue;
//                 }

//                 for (auto& [v, w] : g[u]) {
//                     if (w < mid) {
//                         continue;
//                     }
//                     if (dis[v] > dis[u] + w) {
//                         dis[v] = dis[u] + w;
//                         q.push({dis[v], v});
//                     }
//                 }
//             }
//             return false;
//         };

//         if (!check(l)) {
//             return -1;
//         }

//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             if (check(mid)) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return r;
//     }
// };