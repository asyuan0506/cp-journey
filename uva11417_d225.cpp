#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> result(502, vector<int> (502, 0));

int GCD(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (result[a][b] > 0)
        return result[a][b];
    while ((a %= b) && (b %= a));
    return a + b;
}

int main()
{
    const int maxN = 501;
    int ans[maxN];
    ans[0] = 0;
    for (int i = 1; i < maxN; i++)
    {
        ans[i] = ans[i - 1];
        for (int j = 1; j <= i - 1; j++)
            ans[i] += GCD(j, i);
    }

    int N;
    while (cin >> N && N != 0)
    {
        cout << ans[N] << "\n"; 
        /* Naive
        int G = 0;
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
                G += GCD(i, j);
        }
        cout << G << "\n";
        */
    }

    return 0;
}