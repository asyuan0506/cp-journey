#include <bits/stdc++.h>

using namespace std;

vector<int> BuildF(string &s)
{
    const int len = s.size();
    vector<int> F(len);
    F[0] = -1;

    for (int i = 1, pos = -1; i < len; i++)
    {
        while (pos != -1 && s[i] != s[pos + 1])
            pos = F[pos];
        if (s[i] == s[pos + 1])
            pos++;
        F[i] = pos;
    }
    return F;
}

bool match(string &s, string &t, vector<int> &F)
{
    for (int i = 0, pos = -1; i < s.size(); i++)
    {
        while (pos != -1 && s[i] != t[pos + 1])
            pos = F[pos];
        if (s[i] == t[pos + 1])
            pos++;
        if (pos == t.size() - 1)
            return true;
    }
    return false;
}

int main()
{
    // for (int i = -3; i <= 3; i++)
    //     cout << "I: " << i << " ~I: " << ~i << " Bool I: " << (bool)~i << endl;
    string t = "aabaacaabaacd";
    vector<int> F = BuildF(t);
    string s = "xyzaabxyzaabaacaabadcd";
    cout << match(s, t, F);
    return 0;
}