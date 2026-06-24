#include <bits/stdc++.h>

using namespace std;

struct rock
{
    char c; // Indicate big/small and immersed
    int p;
};

int main()
{
    int t;
    cin >> t;
    int Case = 0;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<rock> r(n); 
        for (int i = 0; i < n; i++)
        {
            char tmp;
            cin >> r[i].c >> tmp >> r[i].p;
        }
        int to = 0;
        int back = 0;
        int min_max_leap = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (r[i].c == 'B')
            {
                min_max_leap = max(min_max_leap, r[i].p - to);
                to = r[i].p;
                min_max_leap = max(min_max_leap, r[i].p - back);
                back = r[i].p;
            }
            else
            {
                if (to >= back)
                {
                    min_max_leap = max(min_max_leap, r[i].p - back);
                    back = r[i].p;
                }
                else
                {
                    min_max_leap = max(min_max_leap, r[i].p - to);
                    to = r[i].p;
                }
            }
        }
        min_max_leap = max(min_max_leap, max(d - to, d - back));
        cout << "Case " << ++Case << ": " << min_max_leap << "\n";
    }

    return 0;
}