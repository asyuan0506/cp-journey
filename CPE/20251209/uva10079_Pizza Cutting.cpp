#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    while (cin >> n && n >= 0)
    {
        long long add = (2 + n) * (n - 1) / 2;
        long long ans = 2 + add;
        cout << ans << "\n";
    }
    
    return 0;
}