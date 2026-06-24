#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    string a, b;
    char op;
    while (cin >> a >> op >> b)
    {
        long long dividend = 0;
        long long divisor = 0;
        int idx = 0;
        for (idx; idx < b.size(); idx++)
        {
            if (idx < a.size())
                dividend = dividend * 10 + (a[idx] - '0');
            divisor = divisor * 10 + (b[idx] - '0');
        }
        string q = "";
        q += (dividend / divisor + '0');
        if (q == "0" && a.size() > b.size())
            q = "";
        long long r = dividend % divisor;
        for (idx; idx < a.size(); idx++)
        {
            dividend = r * 10 + (a[idx] - '0');
            q += (dividend / divisor + '0');
            r = dividend % divisor;
        }
        if (op == '%')
            cout << r << "\n";
        else
            cout << q << "\n";
    }
    */
    string a;
    char op;
    long long b;
    while (cin >> a >> op >> b)
    {
        string q = "";
        long long r = 0;
        for (int i = 0; i < a.size(); i++)
        {
            r = r * 10 + (a[i] - '0');
            q += (r / b + '0');
            r %= b;
        }
        if (op == '/')
        {
            bool zero = true;
            for (char c : q)
            {
                if (zero)
                    zero = c == '0';
                if (!zero)
                    cout << c;
            }
            if (zero)
                cout << 0;
        }
        else
            cout << r;
        cout << "\n";
    }
    return 0;
}