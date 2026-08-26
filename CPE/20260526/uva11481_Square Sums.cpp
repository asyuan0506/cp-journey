#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
vector<long long> factorial;
vector<long long> inv_factorial;

long long my_pow(long long num, int pwr)
{
    long long res = 1, cur = num;
    for (; pwr; pwr >>= 1)
    {
        if (pwr & 1)
            res = (res * cur) % MOD;
        cur = cur * cur % MOD;
    }
    return res;
}

long long modular_inv(long long num) // a ^ (p - 1) mod p = 1 -> a ^ (p - 2) mod p = a ^ -1 mod p
{
    return my_pow(num, MOD - 2);
}

long long comb(int n, int m)
{
    return factorial[n] * inv_factorial[m] % MOD * inv_factorial[n - m] % MOD;
}

int main()
{
    int T;
    cin >> T;
    factorial.resize(1001);
    inv_factorial.resize(1001);
    factorial[0] = 1;
    inv_factorial[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv_factorial[i] = modular_inv(factorial[i]);
    }
    int Case = 0;
    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        int multiplier = 1;
        long long ans = 0;
        int forbidden = M - K;
        for (int i = 0; i <= forbidden; i++)
        {
            ans += comb(forbidden, i) * factorial[N - K - i] * multiplier % MOD;
            ans = (ans + MOD) % MOD;
            multiplier *= -1;
        }
        ans = ans * comb(M, K) % MOD;
        cout << "Case " << ++Case << ": " << ans << "\n";
    }

    return 0;
}