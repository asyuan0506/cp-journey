#include <bits/stdc++.h>

using namespace std;

/*
bool is_prime[100010042];

int main()
{
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < 100010042; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j < 100010042; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int a, b;
    while (cin >> a >> b)
    {
        int cnt = 0;
        int element_cnt = b - a + 1;
        for (int i = a; i <= b; i++)
        {
            if (is_prime[i * i + i + 41])
                cnt++;
        }
        double ans = round((double)cnt / (double)element_cnt * 10000) / 100;
        cout << setprecision(2) << fixed << ans << "\n";
    }

    return 0;
}
*/

const int maxn = 10005;
int p[maxn];

bool IsPrime(int n)
{
    int test = n * n + n + 41;
    if (test % 2 == 0)
        return false;
    for (int i = 3; i * i <= test; i++)
    {
        if (test % i == 0)
            return false;
    }
    return true;
}

int main()
{
    memset(p, -1, sizeof(p)); // -1: unknown 0: not prime 1: prime
    int a, b;
    while (cin >> a >> b)
    {
        int cnt = 0;
        for (int i = a; i <= b; i++)
        {
            if (p[i] == -1)
                p[i] = IsPrime(i);
            if (p[i] == 1)
                cnt++;
        }
        double ans = round((double)cnt / (double)(b - a + 1) * 10000) / 100;
        cout << setprecision(2) << fixed << ans << "\n";
    }

    return 0;
}