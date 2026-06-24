#include <bits/stdc++.h>

using namespace std;

bool mul3(string &s)
{
    // 所有位數相加為 3 的倍數
    int sum = 0;
    for (char c : s)
    {
        sum += c - '0';
    }
    if (sum % 3 == 0)
        return true;
    else
        return false;
}

bool mul4(string &s)
{
    // 後兩位為 4 的倍數
    int len = s.size();
    int last2 = (s[len - 2] - '0') * 10 + s[len - 1] - '0';
    if (last2 % 4 == 0)
        return true;
    else
        return false;
}

bool mul5(string &s)
{
    // 尾數 0 或 5
    char last = s[s.size() - 1];
    if (last == '0' || last == '5')
        return true;
    else
        return false;
}

bool mul11(string &s)
{
    // 奇位數與偶位數相差和為 0 或 11 倍數
    int acc = 0;
    int positive = 1;
    for (char c : s)
    {
        acc += positive * (c - '0');
        positive *= -1;
    }
    if (abs(acc) % 11 == 0) // -0.0?
        return true;
    else
        return false;
}

bool is_leap(string &s)
{
    int len = s.size();
    if (s[len - 2] == '0' && s[len - 1] == '0')
    {
        string tmp = s.substr(0, len - 2);
        if (mul4(tmp))
            return true;
        else
            return false;
    }
    if (mul4(s))
        return true;
    else
        return false;
}

bool is_hulu(string &s)
{
    return mul3(s) && mul5(s);
}

bool is_bulu(string &s)
{
    // Check leap year first
    return mul5(s) && mul11(s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string year;
    bool first = true;
    while (cin >> year)
    {
        if (first)
            first = false;
        else
        {
            cout << "\n";
        }

        bool leap = is_leap(year);
        bool hulu = is_hulu(year);
        bool bulu = (leap) ? is_bulu(year) : false;
        if (leap)
            cout << "This is leap year.\n";
        if (hulu)
            cout << "This is huluculu festival year.\n";
        if (leap && bulu)
            cout << "This is bulukulu festival year.\n";
        if (!leap && !hulu && !bulu)
            cout << "This is an ordinary year.\n";
    }

    return 0;
}