#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int cap, t, n;
        cin >> cap >> t >> n;
        vector<pair<long long, long long>> jars(n);
        for (int i = 0; i < n; i++)
            cin >> jars[i].first >> jars[i].second; // first: cap, second: temp

        bool found = false;
        double min_diff = 1e5;
        int ans_a, ans_b;
        for (int i = 0; i < n; i++)
        {
            long long now_cap = 0;
            long long weighted_temp = 0;
            for (int j = i; j < n; j++)
            {
                weighted_temp += jars[j].first * jars[j].second;
                now_cap += jars[j].first;
                if (now_cap > cap) break;
                if (2 * now_cap < cap) continue;
                {
                    double diff = (double)weighted_temp / (double)now_cap - t;
                    if (abs(diff) > 5.0) continue;
                    if (abs(diff) < min_diff)
                    {
                        found = true;
                        ans_a = i;
                        ans_b = j;
                        min_diff = abs(diff);
                    }
                }
            }
        } 
        if (found)
        {
            cout << ans_a << " " << ans_b << "\n";
        }
        else
            cout << "Not possible\n";
    }


    return 0;
}