#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int cnt = 0;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        cout << "Scenario #" << ++cnt << "\n Frog Distance = ";
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points[i] = make_pair(x, y);
        }
        // Prim's
        // double dist[201][201];
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i; j < n; j++)
        //     {
        //         dist[i][j] = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
        //         dist[j][i] = dist[i][j];
        //     }
        // }
        // vector<int> parent(n, -1);
        // parent[0] = 0;
        // while (parent[1] == -1)
        // {
        //     pair<int, double> min_dist = make_pair(-1, 1e+300);
        //     int tmp_parent = -1;
        //     for (int i = 0; i < n; i++)
        //     {
        //         if (parent[i] == -1)
        //             continue;
        //         for (int j = 1; j < n; j++)
        //         {
        //             if (parent[j] != -1)
        //                 continue;

        //             if (dist[i][j] < min_dist.second)
        //             {
        //                 min_dist = make_pair(j, dist[i][j]);
        //                 tmp_parent = i;
        //             }
        //         }
        //     }
        //     if (min_dist.first == -1)
        //         break;
        //     parent[min_dist.first] = tmp_parent;
        // }
        // double frog_distance = 0.0;
        // int parent_tracker = 1;
        // while (parent_tracker != 0)
        // {
        //     int now_parent = parent[parent_tracker];
        //     frog_distance = max(frog_distance, dist[now_parent][parent_tracker]);
        //     parent_tracker = now_parent;
        // }
        // cout << setprecision(3) << fixed;
        // cout << sqrt(frog_distance) << endl;

        // Floyd-Warshall
        double dist[201][201];
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                double dis = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
                dist[i][j] = dis;
                dist[j][i] = dis;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dist[j][k] = min(dist[j][k], max(dist[j][i], dist[i][k]));

        cout << setprecision(3) << fixed << sqrt(dist[0][1]) << endl;
    }
    return 0;
}