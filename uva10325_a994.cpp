#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)
{
    while ((a %= b) && (b %= a));
    return a + b;
}

long long LCM(long long a, long long b)
{
    return a / GCD(a, b) * b; // Division first prevent overflow
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N, M;
    while (cin >> N >> M)
    {
        vector<long long> nums(M);
        for (int i = 0; i < M; i++)
            cin >> nums[i];

        long long divisible_cnt = 0;
        for (int i = 1; i < (1 << M); i++) // 遍歷所有 2 ^ M - 1 個組合
        {
            long long cur = 1;
            int cnt = 0;
            for (int j = 0; j < M; j++) 
            {
                if (i & (1 << j)) // 如果第 j 個 bit 為 1，代表要選
                {
                    cur = LCM(cur, nums[j]);
                    cnt++;
                }    
                if (cur > N)
                    break;
            }
            if (cur > N)
                continue;
            if (cnt % 2)
                divisible_cnt += N / cur;
            else
                divisible_cnt -= N / cur;
        }
        
        cout << N - divisible_cnt << "\n";
    }

    return 0;
}