#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(32768, true);
    for (int i = 2; i < 32768; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j < 32768; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        int cnt = 0;
        for (int i = 3; i <= n / 2; i++) // 1 not count IDK why zerojudge said only odd prime number
        {
            if (is_prime[i] && is_prime[n - i])
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}