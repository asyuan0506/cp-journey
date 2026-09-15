#include <bits/stdc++.h>

using namespace std;

long long pw(long long num, int p)
{
    long long res = 1;
    long long base = num;
    for (; p >= 1; p >>= 1)
    {
        if (p & 1)
            res *= base;
        base *= base;
    }
    return res;
}

int main()
{
    int x;
    while (cin >> x)
    {
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        long long num;
        vector<long long> nums;
        while (ss >> num)
            nums.push_back(num);
        
        long long sum = 0;
        long long n = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            sum += nums[i] * n * pw(x, n - 1); // Actually don't need fast exp, just build array is fine.
            n++;
        }
        cout << sum << "\n";
    }

    return 0;
}