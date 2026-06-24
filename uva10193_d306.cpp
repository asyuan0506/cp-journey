#include <bits/stdc++.h>

using namespace std;

// int gcd(int a, int b)
// {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }
int gcd(int a, int b)
{
    while ((a %= b) && (b %= a));
    return a + b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int Case = 0;
    while (N--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = 0, n2 = 0; // no string more than 30 char
        int mul = 1;
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            n1 += (s1[i] - '0') * mul;
            mul = mul << 1; // mul *= 2;
        }
        mul = 1;
        for (int i = s2.size() - 1; i >= 0; i--)
        {
            n2 += (s2[i] - '0') * mul;
            mul = mul << 1;
        }
        bool love = gcd(n1, n2) > 1;

        cout << "Pair #" << ++Case << ": ";
        if (love)
            cout << "All you need is love!\n";
        else
            cout << "Love is not all you need!\n";
    }

    return 0;
}