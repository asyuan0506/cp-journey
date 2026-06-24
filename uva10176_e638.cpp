#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int MOD = 131071;
    string s, buf;
    while (cin >> buf)
    {
        s += buf;
        if (buf[buf.size() - 1] != '#')
            continue;

        long long ans = 0;
        int mul = 1;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ans += mul;
                ans %= MOD;
            }
            mul *= 2;
            mul %= MOD;
        }
        if (ans > 0)
            cout << "NO\n";
        else
            cout << "YES\n";

        s.clear();
    }

    return 0;
}