#include <bits/stdc++.h>

using namespace std;

int a[130], b[5], dot; // 99.999 ^ 25 is about 125 digit

void mul()
{
    for (int i = 129; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            a[i + j] += a[i] * b[j];
        }
    }

    int carry = 0;
    for (int i = 0; i <= 129; i++)
    {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n = 0;
        if (s[7] != ' ')
            n = (s[7] - '0') * 10;
        n += s[8] - '0';

        s = s.substr(0, 6);
        while (s[s.length() - 1] == '0')
            s = s.substr(0, s.length() - 1);
        int cnt = s.length() - 2; // numbers count
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
                dot = s.length() - 1 - i; // number count right of the dot
            else
            { // Reverse
                a[cnt] = s[i] - '0';
                b[cnt] = a[cnt];
                cnt--;
            }
        }
        dot *= n;
        b[0]--; // A_new = A_old * B => A_old + A_old * (B - 1)
        for (int i = 0; i < 4; i++)
        {
            if (b[i] < 0)
            {
                b[i + 1]--;
                b[i] += 10;
            }
        }

        for (int i = 1; i < n; i++)
            mul();

        int l = 129;
        int r = 0;
        while (l >= dot && a[l] == 0)
            l--;
        while (r < dot && a[r] == 0)
            r++;
        for (l; l >= r; l--)
        {
            if (l == dot - 1)
                cout << '.';
            cout << a[l];
        }
        cout << "\n";
    }

    return 0;
}