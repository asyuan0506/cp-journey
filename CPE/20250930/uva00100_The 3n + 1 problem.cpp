#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> memo;

int recursive(int num)
{
    if (memo.count(num) > 0)
        return memo[num];
    if (num % 2)
        memo[num] = 1 + recursive(3 * num + 1);
    else
        memo[num] = 1 + recursive(num / 2);
    return memo[num];
}

int main()
{
    memo[1] = 1;

    int a, b;
    while (cin >> a >> b)
    {
        cout << a << " " << b << " ";
        int ans = 0;
        if (a > b) swap(a, b);
        for (int i = a; i <= b; i++)
            ans = max(ans, recursive(i));
        cout << ans << "\n";
    }

    return 0;
}