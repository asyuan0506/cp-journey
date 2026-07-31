class Solution {
public:
    // Too complicated
    // void dfs(int n, vector<int>& visited, vector<vector<int>>& g)
    // {
    //     int flower_type = 1;
    //     for (int i = 0; i < g[n].size(); i++) // Find the available color
    //     {
    //         int nxt = g[n][i];
    //         if (flower_type == visited[nxt])
    //         {
    //             flower_type++;
    //             i = -1;
    //             continue;
    //         }
    //     }
    //     visited[n] = flower_type;
    //     for (int i = 0; i < g[n].size(); i++)
    //     {
    //         int nxt = g[n][i];
    //         if (visited[nxt] == 0)
    //         {
    //             visited[nxt] = -1;
    //             dfs(nxt, visited, g);
    //         }
    //     }
    // }
    // vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    //     vector<vector<int>> g(n);
    //     for (vector<int> path : paths)
    //     {
    //         g[path[0] - 1].push_back(path[1] - 1);
    //         g[path[1] - 1].push_back(path[0] - 1);
    //     }

    //     vector<int> visited(n, 0); // Number denotes the flower type, 0 is not visited, -1 is not yet visit but in the stack
    //     for (int i = 0; i < n; i++) // Since there will be several group, dfs each group
    //     {
    //         if (visited[i] == 0)
    //             dfs(i, visited, g);
    //     }
    //     return visited;
    // }


    // Since at most 3 neighbors, and we can use 4 color, so there's always a color available.
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (vector<int> path : paths)
        {
            g[path[0] - 1].push_back(path[1] - 1);
            g[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int> color(n, 0);
        for (int i = 0; i < n; i++)
        {
            bool used[5] = { false };
            for (int neighbor : g[i])
                used[color[neighbor]] = true;
            
            int use = 1;
            for (use; use <= 4; use++)
            {
                if (!used[use])
                {
                    color[i] = use;
                    break;
                }
            }
        }
        return color;
    }
};