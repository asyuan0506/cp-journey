/*
    Fallacy: https://gemini.google.com/share/cd5babb10e9e
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int coin[5] = {1, 5, 10, 25, 50};
    long long ans[7490] = {0};
    ans[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = coin[i]; j < 7490; j++)
        {
            ans[j] += ans[j - coin[i]];
        }
    }
    while (cin >> n)
    {
        cout << ans[n] << endl;
    }

    return 0;
}