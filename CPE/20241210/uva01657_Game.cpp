#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        vector<vector<pair<int, int>>> sum(2 * N);
        unordered_map<int, vector<pair<int, int>>> product;
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                sum[i + j].push_back({i, j});
                product[i * j].push_back({i, j});
            }
        }
        for (int i = 0; i < M; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 3; j < sum.size(); j++)
                {
                    if (sum[j].size() == 1)
                    {
                        int a = sum[j][0].first, b = sum[j][0].second;
                        int tmp = a * b;
                        for (int k = 0; k < product[tmp].size(); k++)
                        {
                            if (product[tmp][k].first == a && product[tmp][k].second == b)
                            {
                                product[tmp].erase(product[tmp].begin() + k);
                                break;
                            }
                        }
                        sum[j].clear();
                    }
                }
            }
            else if (i % 2 == 1)
            {
                for (auto &i : product)
                {
                    vector<pair<int, int>> &v = i.second;
                    if (v.size() == 1)
                    {
                        int a = v[0].first, b = v[0].second;
                        int tmp = a + b;
                        for (int k = 0; k < sum[tmp].size(); k++)
                        {
                            if (sum[tmp][k].first == a && sum[tmp][k].second == b)
                            {
                                sum[tmp].erase(sum[tmp].begin() + k);
                                break;
                            }
                        }
                        v.clear();
                    }
                }
            }
        }
        vector<pair<int, int>> ans;
        if (M % 2 == 0)
        {
            for (int i = 0; i < sum.size(); i++)
            {
                if (sum[i].size() == 1)
                {
                    ans.push_back(sum[i][0]);
                }
            }
        }
        else
        {
            for (auto &i : product)
            {
                vector<pair<int, int>> &v = i.second;
                if (v.size() == 1)
                {
                    ans.push_back(v[0]);
                }
            }
        }
        sort(ans.begin(), ans.end()); // If don't sort, it will get WA although it said "output these pairs in arbitrary order".
        cout << ans.size() << "\n";
        for (auto &i : ans)
        {
            cout << i.first << " " << i.second << "\n";
        }
    }
    

    return 0;
}