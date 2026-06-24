#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        /* Slow
        int cnt = 0;
        int sqrt_N = round(sqrt(N));
        for (int i = 1; i <= sqrt_N; i++)
        {
            if (N % i == 0)
            {
                if (N / i != i)
                    cnt += 2;
                else
                    cnt++;
            }
        }
        if (cnt % 2)
            cout << "yes\n";
        else
            cout << "no\n";
        */
        // Fast, Because only perfect squares have odd number of divisors
        long long sqrt_N = (long long)sqrt(N); // Use long long in UVA, because N up to 2 ^ 32 - 1, while INT max is 2 ^ 31 - 1
        if (sqrt_N * sqrt_N == N)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}