#include <bits/stdc++.h>

using namespace std;

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int pre = v[0];
        int sum = v[0];
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (sum >= v[i])
            {
                sum -= pre;
                ans--;
            }
            sum += v[i];
            pre = v[i];
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}