#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<long long> ways(n + 1, 1);
        for (int i = 5; i <= n; i++)
        {
            ways[i] += ways[i - 5];
        }
        for (int i = 10; i <= n; i++)
            ways[i] += ways[i - 10];
        for (int i = 25; i <= n; i++)
            ways[i] += ways[i - 25];
        for (int i = 50; i <= n; i++)
            ways[i] += ways[i - 50];
        if (ways[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        else
            cout << "There are " << ways[n] << " ways to produce " << n << " cents change.\n";
    }

    return 0;
}