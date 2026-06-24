#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // Solve 1
    // x^2 + x - 2n = 0  (-1 +- sqrt(1 + 8n))/ 2   
    // int CASE;
    // cin >> CASE; 
    // while (CASE--)
    // {
    //     long long n;
    //     cin >> n;
    //     long long ans = (-1 + sqrt(1 + 8 * n)) / 2;
    //     cout << ans << "\n";
    // }
    // Solve 2
    int CASE;
    cin >> CASE;
    while (CASE--)
    {
        long long n;
        cin >> n;
        long long l = 0, r = 2e9;
        while (l <= r)
        {
           long long m = (l + r) / 2;
           long long x1 = (1 + m) * m / 2;
           long long x2 = (m + 2) * (m + 1) / 2;
           if (x1 <= n && n < x2)
            {
                cout << m << "\n";
                break;
            }
            else if (x1 < n)
                l = m + 1;
            else
                r = m - 1;
        }
    }

    return 0;
}