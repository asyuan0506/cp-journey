#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
// Global variable will be initialize to zero
bool not_prime[maxn]; // Use upper bound so must take a prime bigger than 10000

int main()
{
    not_prime[0] = true;
    not_prime[1] = true;
    vector<int> prime;
    for (int i = 2; i < maxn; i++)
    {
        if (!not_prime[i])
        {
            prime.push_back(i);
            for (int j = i + i; j < maxn; j += i)
            {
                not_prime[j] = true;
            }
        }
    }

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int cnt = 0;

        for (int i = 0; prime[i] <= n; i++)
        {
            int tmp = 0;
            for (int j = i; tmp < n; j++)
            {
                tmp += prime[j];
                if (tmp == n)
                    break;
            }
            if (tmp == n)
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}