#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, M, li, ri;
    cin >> T;
    while (T--)
    {
        cin >> M;
        vector<pair<int, int>> line;
        while (cin >> li >> ri)
        {
            if (li == 0 && ri == 0)
                break;
            line.push_back(make_pair(li, ri));
        }
        stable_sort(line.begin(), line.end(), cmp);
        int L = 0;
        int idx = 0;
        vector<pair<int, int>> ans;
        while (L < M)
        {
            int maxR = 0;
            for (int i = idx; i < line.size(); i++)
            {
                li = line[i].first;
                ri = line[i].second;
                if (li > L)
                    break;
                if (ri > maxR)
                {
                    maxR = ri;
                    idx = i + 1;
                }
            }
            if (maxR)
            {
                ans.push_back(line[idx - 1]);
                L = maxR;
            }
            else
                break;
        }
        if (L < M)
        {
            cout << "0\n";
        }
        else
        {
            int cnt = ans.size();
            cout << cnt << "\n";
            for (int i = 0; i < cnt; i++)
                cout << ans[i].first << " " << ans[i].second << "\n";
        }

        if (T != 0)
            cout << "\n";
    }

    return 0;
}