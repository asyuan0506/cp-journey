#include <iostream>
#include <string>

using namespace std;

string a, b;
int F[100001];

void buildF(string &t)
{
    const int sz = t.size();
    F[0] = -1;
    for (int i = 1, pos = -1; i < sz; i++)
    {
        while (~pos && t[i] != t[pos + 1])
            pos = F[pos];
        if (t[i] == t[pos + 1])
            pos++;
        F[i] = pos;
    }
}

int match(string &s, string &t)
{
    const int sz = s.size();
    const int tz = t.size();
    int pos = -1;
    for (int i = 0; i < sz; i++)
    {
        if (pos + 1 == tz) // t inside s but not at tail
            //pos = -1; // Bug: a = "xababab" b = "abab" -> xabababab instead of xababab
            pos = F[pos]; // Fix: continue searching for next match
        while (~pos && s[i] != t[pos + 1])
            pos = F[pos];
        if (s[i] == t[pos + 1])
            pos++;
    }
    return pos;
}

int main()
{
    
    while (cin >> a >> b)
    {
        buildF(b);
        int res = match(a, b);
        string ans1;
        if (res == -1)
            ans1 = a + b;
        else
            ans1 = a + b.substr(res + 1);
        buildF(a);
        res = match(b, a);
        string ans2;
        if (res == -1)
            ans2 = b + a;
        else
            ans2 = b + a.substr(res + 1);
        if (ans1.length() > ans2.length() ||
            ans1.length() == ans2.length() && ans1 > ans2)
            swap(ans1, ans2);
        cout << ans1 << "\n";
    }

    return 0;
}