// class Solution {
// public:
//     void dfs(int k, vector<bool>& suspicious, vector<vector<vector<int>>>& nodes)
//     {
//         for (int nxt : nodes[k][1])
//         {
//             if (!suspicious[nxt])
//             {
//                 suspicious[nxt] = true;
//                 dfs(nxt, suspicious, nodes);
//             }
//         }
//     }
//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
//         // Mark all suspicious nodes.
//         // Check whether any suspicious node is invoked by non-suspicious node.
//         // If such node exists, no suspicious nodes can be removed.
//         vector<bool> suspicious(n, false);
//         vector<vector<vector<int>>> nodes(n, vector<vector<int>>(2)); // 0: in, 1: out
//         for (vector<int>& i : invocations)
//         {
//             int from = i[0], to = i[1];
//             nodes[from][1].push_back(to);
//             nodes[to][0].push_back(from);
//         }

//         suspicious[k] = true;
//         dfs(k, suspicious, nodes);
        
//         // O(n + m):
//         // Although the loops are nested, each incoming edge is checked at most once.
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//         {
//             if (!suspicious[i])
//             {
//                 ans.push_back(i);
//                 continue;
//             }
//             for (int from : nodes[i][0])
//             {
//                 if (!suspicious[from])
//                 {
//                     ans.clear();
//                     for (int j = 0; j < n; j++)
//                         ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    void dfs(int k, vector<bool>& suspicious, vector<vector<int>>& edges)
    {
        for (int node : edges[k])
        {
            if (!suspicious[node])
            {
                suspicious[node] = true;
                dfs(node, suspicious, edges);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> suspicious(n, false);
        vector<vector<int>> edges(n);
        for (vector<int>& i : invocations)
            edges[i[0]].push_back(i[1]);

        suspicious[k] = true;
        dfs(k, suspicious, edges);
        
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (suspicious[i])
            {
                continue;   
            }
            ans.push_back(i);
            for (int node : edges[i])
            {
                if (suspicious[node])
                {
                    vector<int> tmp(n);
                    iota(tmp.begin(), tmp.end(), 0);
                    return tmp;
                }
            }    
        }
        
        return ans;
    }
};