#include <bits/stdc++.h>

using namespace std;

#define int long long

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    while ((a %= b) && (b %= a));
    return a + b;
}

signed main()
{
    int first;
    while (cin >> first && first != 0)
    {
        vector<int> nums(1, first);
        int num;
        while (cin >> num && num != 0)
        {
            nums.push_back(num);
        }
        int gcd = abs(nums[0] - nums[1]);
        for (int i = 1; i < nums.size(); i++)
        {
            gcd = GCD(gcd, abs(nums[i] - nums[i - 1])); // abs because there might be negative num. Remainder = 0 so no problem
        }
        cout << gcd << "\n";
    }

    return 0;
}