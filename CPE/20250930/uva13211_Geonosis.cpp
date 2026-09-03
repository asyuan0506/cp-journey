#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int towers;
        cin >> towers;
        vector<vector<int>> dis(towers, vector<int> (towers));
        for (int i = 0; i < towers; i++)
        {
            for (int j = 0; j < towers; j++)
                cin >> dis[i][j];
        }
        vector<int> seq(towers);
        for (int i = 0; i < towers; i++)
            cin >> seq[i];

        vector<bool> used(towers, true); // Reverse the process
        long long energy = 0;
        for (int i = towers - 1; i >= 0; i--)
        {
            int add = seq[i];
            used[add] = false;
            for (int j = 0; j < towers; j++)  // Floyd-Warshall
            {
                for (int k = 0; k < towers; k++)
                {
                    dis[j][k] = min(dis[j][k], dis[j][add] + dis[add][k]);
                }
            }
            for (int j = 0; j < towers; j++)
            {
                if (used[j]) continue;
                for (int k = 0; k < towers; k++)
                {
                    if (used[k]) continue;
                    energy += dis[j][k];
                }
            }
        }
        
        cout << energy << "\n";
    }

    return 0;
}   