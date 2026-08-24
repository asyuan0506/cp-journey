#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        long long res = 0;

        // Solution 1: Jump same quotient
        // long long i = 1;
        // while (i <= n)
        // {
            
        //     // floor(n / i) = q 
        //     // find max x such that floor(n / x) = q
        //     // n / x >= q -> n / q >= x

        //     long long q = n / i;
        //     long long r = n / q;
        //     res += q * (r - i + 1);
        //     i = r + 1;
        // }
        
        // Solution 2: Symmetric to i = j
        int t = sqrt(n);
        for (int i = 1; i <= t; i++)
        {
            res += n / i;
        }
        res = 2 * res - t * t;

        cout << res << "\n";
    }

    
    return 0;
}