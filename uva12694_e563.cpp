#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int d;
    cin >> d;
    while (d--)
    {
        int s, f;
        vector<vector<int>> events(10 + 1);  // idx: end time
        while (cin >> s >> f && s + f)
        {
            events[f].push_back(s);
        }
        int cnt = 0;
        int next = 0;
        for (int i = 1; i <= 10; i++)
        {
            if (i < next)
                continue;
            sort(events[i].begin(), events[i].end(), cmp);
            if (!events[i].empty() && events[i][0] >= next)
            {
                next = i;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }


    return 0;
}