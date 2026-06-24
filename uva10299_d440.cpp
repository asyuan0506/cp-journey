// Euler Fucntion: https://www.youtube.com/watch?v=osge0_lZTaY
// Code: https://yuihuang.com/euler-function/
// Code: https://yuihuang.com/zj-d440/

#include <bits/stdc++.h>

using namespace std;

int phi(int n)
{
    if (n < 2)
        return 0;
    int ret = n;
    int sq = sqrt(n);
    for (int p = 2; p <= sq; p++)
    {
        if (n % p == 0)
        {
            while (n % p == 0) // 質因數分解
                n /= p;
            ret -= ret / p;  // n * (p - 1)/p -> n - n/p
        }
        if (n == 1)
            break;
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while (cin >> N && N != 0)
    {
        cout << phi(N) << "\n";
    }

    return 0;
}