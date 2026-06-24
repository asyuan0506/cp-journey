#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long ans[51];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= 50; i++)
        ans[i] = ans[i - 2] + ans[i - 1];
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << ans[n] << endl;
    }
    return 0;
}