#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int Case = 0;
    while (cin >> s && s != "end")
    {
        cout << "Case " << ++Case << ": ";
        vector<char> tops; // record top_most and maintain order
        for (char c : s)
        {
            auto it = lower_bound(tops.begin(), tops.end(), c);
            if (it == tops.end())
                tops.push_back(c);
            else
                *it = c;
        }
        cout << tops.size() << "\n";
    }

    return 0;
}