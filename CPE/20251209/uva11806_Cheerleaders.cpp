#include <bits/stdc++.h>

using namespace std;

const int maxN = 4001;
const int MOD = 1000007;

int comb[maxN][maxN];

void init()
{
    comb[0][0] = 1;
    for (int n = 1; n < maxN; n++)
    {
        comb[n][0] = 1;
        comb[n][n] = 1;
        for (int m = 1; m < n; m++)
        {
            comb[n][m] = (comb[n - 1][m - 1] + comb[n - 1][m]) % MOD;
        }
    }    
}

int main()
{
    init();

    int N;
    cin >> N;
    int Case = 0;
    while (N--) {
        int m, n, k;
        cin >> m >> n >> k;
        int ans = 0;
        for (int mask = 0; mask < (1 << 4); mask++) // bit 0: top  bit 1: bottom  bit 2: left  bit 3: right
        {
            int rows = m, cols = n;
            int cnt = 0;
            if (mask & 1) 
            {
                cnt++;
                rows--;
            }
            if (mask & (1 << 1)) 
            {
                cnt++;
                rows--;
            }
            if (mask & (1 << 2)) 
            {
                cnt++;
                cols--;
            }
            if (mask & (1 << 3)) 
            {
                cnt++;
                cols--;
            }
            int cells = rows * cols;
            if (cells < k) continue;

            if (cnt % 2)
                ans = (ans - comb[cells][k] + MOD) % MOD;
            else
                ans = (ans + comb[cells][k]) % MOD;

        }
        cout << "Case " << ++Case << ": " << ans << "\n";
    }

    return 0;
}