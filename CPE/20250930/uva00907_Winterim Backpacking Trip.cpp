    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        int N, K;
        while (cin >> N >> K)
        {
            vector<int> camp(N + 1);
            vector<int> pre(N + 2);
            pre[0] = 0;
            for (int i = 0; i <= N; i++)
            {
                cin >> camp[i];
                pre[i + 1] = pre[i] + camp[i];
            }

            vector<vector<int>> dp(K + 1, vector<int> (N + 1, INT_MAX));
            for (int i = 0; i <= N; i++)
                dp[0][i] = pre[i + 1];
            for (int i = 1; i <= K; i++)
            {
                for (int j = 0; j <= N; j++)
                {
                    for (int k = 0; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], max(dp[i - 1][k], + pre[j + 1] - pre[k + 1]));
                    }
                }
            }
            cout << dp[K][N] << "\n";
        }


        return 0;
    }