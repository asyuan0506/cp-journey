#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
        nums.push_back(num);
    const int n = nums.size();

    // Solution 1: DP, assume nums[i] as end of subsequence, O(N^2)
    vector<int> dp(n, 1);
    // int mx = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (nums[j] < nums[i])
    //         {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //             mx = max(mx, dp[i]);
    //         }
    //     }
    // } 
    // cout << mx << "\n";
    
    // Show subsequence
    vector<int> pre(n, -1);
    int best_idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
                if (dp[i] > dp[best_idx])
                {
                    best_idx = i;
                }
            }
        }
    }
    int idx = best_idx;
    vector<int> ans;
    while (idx != -1)
    {
        ans.push_back(nums[idx]);
        idx = pre[idx];
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
    cout << "\n";

    // Solution 2: Binary Search, tails[i]: minimum possible ending value with length i + 1, O(N logN)
    vector<int> tails;
    // for (int x : nums)
    // {
    //     auto it = lower_bound(tails.begin(), tails.end(), x);

    //     if (it == tails.end())
    //     {
    //         tails.push_back(x);
    //     }
    //     else
    //         *it = x;
    // }
    // cout << tails.size() << "\n";

    // vector<int> dp2(n); // Reachable length at index i
    // int L = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int x = nums[i];
    //     auto it = lower_bound(tails.begin(), tails.end(), x);
    //     if (it == tails.end())
    //     {
    //         tails.push_back(x);
    //         dp2[i] = ++L;
    //     }
    //     else
    //     {
    //         *it = x;
    //         dp2[i] = it - tails.begin() + 1;
    //     }
    // }
    
    // vector<int> ans2;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (dp2[i] == L)
    //     {
    //         ans2.push_back(nums[i]);
    //         --L;
    //     }
    // }
    // reverse(ans2.begin(), ans2.end());
    // for (int x : ans2)
    //     cout << x << " ";
    // cout << "\n";

    // Solution 2 (Another way)
    vector<int> tails_idx;
    vector<int> pre2(n, -1);
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int pos = lower_bound(tails.begin(), tails.end(), x) - tails.begin();
        if (pos == tails.size())
        {
            tails.push_back(x);
            tails_idx.push_back(i);
        }
        else
        {
            tails[pos] = x;
            tails_idx[pos] = i;
        }
        if (pos > 0)
        {
            pre2[i] = tails_idx[pos - 1];
        }
    }
    vector<int> ans2;
    int cur = tails_idx.back();
    while (cur != -1)
    {
        ans2.push_back(nums[cur]);
        cur = pre2[cur];
    }
    reverse(ans2.begin(), ans2.end());
    for (int x : ans2)
        cout << x << " ";
    cout << "\n";

    return 0;
}