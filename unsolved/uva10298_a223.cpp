#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s) && s != ".")
    {
        int len = s.size();
        /*
        for (int i = 1; i <= len; i++)
        {
            if (len % i != 0) // IMPORTANT or u will waste a lot of time
                continue;
            string cur = s.substr(0, i);
            bool found = true;
            for (int j = i; j < len; j += i)
            {
                if (s.substr(j, i) != cur)
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                cout << len / i << "\n";
                break;
            }
        }
        */
        vector<int> e_kmp(len);
        e_kmp[0] = -1;
        int neg_pos = 0;
        for (int i = 1, pos = -1; i < len; i++)
        {
            while (pos != -1 && s[i] != s[pos + 1])
                pos = e_kmp[pos];
            if (s[i] == s[pos + 1])
                pos++;
            e_kmp[i] = pos;
            if (pos == -1)
                neg_pos = i;
        }
        // Not Know Why yet
        if (len % (neg_pos + 1) != 0)
            cout << 1 << "\n";
        else if (neg_pos + 1 > len / 2)
            cout << 1 << "\n";
        else 
            cout << len / (neg_pos + 1) << "\n";
    }

    return 0;
}