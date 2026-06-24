#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     int T, l, p;
//     cin >> T;
//     while (T--)
//     {
//         cin >> l >> p;
//         vector<int> bar(p);
//         for (int i = 0; i < p; i++)
//             cin >> bar[i];

//         int num = 1;
//         for (int i = 1; i < p; i++)
//         {
//             num <<= 1;
//             num++;
//         }
//         bool found = false;
//         for (int i = num; i >= 0; i--)
//         {
//             int sum = 0;
//             for (int j = 0; j < p; j++)
//             {
//                 if ((i >> j) & 1)
//                     sum += bar[j];
//                 if (sum == l)
//                 {
//                     found = true;
//                     break;
//                 }
//             }
//             if (found)
//                 break;
//         }
//         if (found)
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }

//     return 0;
// }

int main()
{
    int CASE, l, p;
    cin >> CASE;
    while (CASE--)
    {
        cin >> l >> p;
        vector<int> bars(p);
        for (int i = 0; i < p; i++)
            cin >> bars[i];
        vector<int> dp(l + 1, 0);
        for (int len : bars)
        {
            for (int i = l; i >= len; i--)
            {
                dp[i] = max(dp[i], dp[i - len] + len);
            }
        }
        if (l == dp[l])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}