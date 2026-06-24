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
    int n;
    double l, w;
    while (cin >> n >> l >> w)
    {
        vector<pair<double, double>> sprinklers; // first: left second: right
        for (int i = 0; i < n; i++)
        {
            double pos, radius;
            cin >> pos >> radius;
            double dis = radius * radius - w * w / 4.0; // (w / 2) * (w / 2)
            if (dis < 0.0)  // sqrt can't use on negative value
                continue;
            dis = sqrt(dis);
            sprinklers.push_back(make_pair(pos - dis, pos + dis));
        }
        sort(sprinklers.begin(), sprinklers.end(), cmp);
        double left = 0.0;
        int cnt = 0;
        int i = 0;
        while (left < l)
        {
            double right_most = left;
            while (i < sprinklers.size() && sprinklers[i].first <= left)
            {
                right_most = max(right_most, sprinklers[i].second);
                i++;
            }
            if (right_most > left)
            {
                cnt++;
                left = right_most;
            }
            else
                break;
        }
        if (left < l)
            cout << "-1\n";
        else
            cout << cnt << "\n";
    }

    return 0;
}