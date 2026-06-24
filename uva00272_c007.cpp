#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool cur = 0; // 0: `` 1: ''
    while (getline(cin, s))
    {
        string out = "";
        for (char c : s)
        {
            if (c == '"')
            {
                out += (cur)? "\'\'" : "``";
                cur = !cur;
            } 
            else
                out += c;
        }
        cout << out << "\n";
    }

    return 0;
}