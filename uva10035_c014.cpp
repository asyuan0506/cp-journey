#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    int cnt;
    bool carry;
    int d_a, d_b;
    while (cin >> a >> b && a || b)
    {
        cnt = 0;
        carry = 0;
        while (a > 0 || b > 0)
        {
            d_a = a % 10;
            d_b = b % 10;
            a /= 10; b /= 10;
            carry = (d_a + d_b + carry) >= 10;
            cnt += carry;
        }
        if (cnt == 0)
            cout << "No carry operation.\n";
        else if (cnt == 1)
            cout << "1 carry operation.\n";
        else 
            cout << cnt << " carry operations.\n";
    }
    return 0;
}