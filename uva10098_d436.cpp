#include <bits/stdc++.h>

using namespace std;

bool cmp(char c1, char c2)
{
    return c1 < c2;
}

void per(string s, string cur, int &len)
{
    if (cur.size() == len)
    {
        cout << cur << "\n";
        return;
    }
    unordered_map<char, bool> used;
    for (int i = 0; i < s.size(); i++)
    {
        if (used.find(s[i]) == used.end())
        {
            used[s[i]] = true;
            per(s.substr(0, i) + s.substr(i + 1), cur + s[i], len);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        int len = s.size();
        per(s, "", len);
        cout << "\n";
        // if (n == 1)  // ZeroJudge need this
        // {
        //     s = "ABCDEFGHI";
        //     len = s.size();
        //     per(s, "", len);
        //     cout << "\n";
        //     n--;
        // }
    }
    return 0;
}