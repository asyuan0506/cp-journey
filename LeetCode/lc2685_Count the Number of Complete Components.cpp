class Solution {
// private:
//     inline static int p[51]; // vertex count
public:
    // int Find(int a)
    // {
    //     return p[a] < 0 ? a : Find(p[a]);
    // }
    // void Union(int a, int b)
    // {
    //     int g1 = Find(a);
    //     int g2 = Find(b);
    //     if (g1 != g2)
    //     {
    //         p[g1] += p[g2];
    //         p[g2] = g1;
    //     }
    // }
    // int countCompleteComponents(int n, vector<vector<int>>& edges) {
    //     for (int i = 0; i < n; i++)
    //         p[i] = -1;
    //     vector<vector<int>> graph(n);
    //     for (int i = 0; i < edges.size(); i++)
    //     {
    //         int a = edges[i][0], b = edges[i][1];
    //         graph[a].push_back(b);
    //         graph[b].push_back(a);
    //         Union(a, b);
    //     }
    //     vector<bool> complete(n, true);
    //     int ans = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int root = Find(i);
    //         if (root == i)
    //             ans++;
    //         if (!complete[root])
    //             continue;
    //         if ( -1 * p[root] != graph[i].size() + 1) // Exists path between any two vertices
    //         {
    //             complete[root] = false;
    //             ans--;
    //         }
    //     }
        
    //     return ans;
    // }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);

        auto find = [&](this auto& self, int a) -> int {
            return root[a] == a ? a : self(root[a]);
        };

        for (vector<int>& edge : edges)
            root[find(edge[0])] = find(edge[1]);

        vector<int> V(n, 0);
        vector<int> E(n, 0);

        for (int i = 0; i < n; i++)
            V[find(i)]++;

        for (vector<int>& edge : edges)
            E[find(edge[0])]++;

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (V[i] && (V[i] * (V[i] - 1) >> 1) == E[i]);
        }
        return res;
    }
};