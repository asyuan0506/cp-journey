#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll max_num(string s)
{
    ll ans = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            ans += tmp;
            tmp = 0;
            ans *= max_num(s.substr(i+1));
            break;
        }
        else if (s[i] == '+')
        {
            ans += tmp;
            tmp = 0;
        }
        else
        {
            tmp = tmp * 10 + (s[i] - '0');
        }
        if (i == s.size() - 1)
            ans += tmp;
    }
    return ans;
}

ll min_num(string s)
{
    ll ans = 1;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            ans *= tmp;
            tmp = 0;
        }
        else if (s[i] == '+')
        {
            ans *= tmp;
            ans += min_num(s.substr(i + 1));
            break;
        }
        else
            tmp = tmp * 10 + (s[i] - '0');
        if (i == s.size() - 1)
            ans *= tmp;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        
        cout << "The maximum and minimum are " << max_num(s) << " and " << min_num(s) << ".\n";
    }

    return 0;
}