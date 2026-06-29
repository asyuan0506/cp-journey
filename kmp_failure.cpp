#include <bits/stdc++.h>

using namespace std;

vector<int> BuildF(string &t)
{
    const int len = t.size();
    vector<int> F(len);
    F[0] = -1;
    for (int i = 1, pos = -1; i < len; i++)
    {
        while (~pos && t[i] != t[pos + 1])
            pos = F[pos];
        if (t[i] == t[pos + 1])
            pos++;
        F[i] = pos;
    }
    return F;
}

bool match(string &s, string &t, vector<int> &F)
{
    for (int i = 0, pos = -1; i < s.size(); i++)
    {
        while (~pos && s[i] != t[pos + 1])
            pos = F[pos];
        if (s[i] == t[pos + 1])
            pos++;
        if (pos + 1 == t.size())
            return true;
    }
    return false;
}

int main()
{
    // for (int i = -3; i <= 3; i++)
    //     cout << "I: " << i << " ~I: " << ~i << " Bool I: " << (bool)~i << endl;
    string t = "aabaacaabadcd"; // aabaacaabaacd : False, aabaacaabadcd : True
    vector<int> F = BuildF(t);
    string s = "xyzaabxyzaabaacaabadcd";
    cout << match(s, t, F);
    return 0;
}