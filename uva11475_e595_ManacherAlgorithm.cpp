// https://hackmd.io/@CynthiaChuang/LeetCode-0005-Longest-Palindromic-Substring
// https://segmentfault.com/a/1190000003914228#articleHeader3

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        string ms = "#";
        for (char c : s)
        {
            ms += c;
            ms += '#';
        }
        const int ms_size = ms.size();
        int mirror = 0;
        int max_right = 0;
        vector<int> rl(ms_size, 1);
        for (int i = 0; i < ms_size; i++)
        {
            if (i < max_right)
                rl[i] = min(rl[2 * mirror - i], max_right - i);
            while (i - rl[i] >= 0 && i + rl[i] < ms_size && ms[i - rl[i]] == ms[i + rl[i]])
                rl[i]++;
            if (i + rl[i] - 1 > max_right)
            {
                mirror = i;
                max_right = i + rl[i] - 1;
            }
            if (max_right == ms_size - 1)
            {
                string sub = s.substr(0, s.size() - (rl[mirror] - 1));
                reverse(sub.begin(), sub.end());
                cout << s << sub << "\n";
                break;
            }
        }
        // for (int i = mirror - rl[mirror]; i >= 0; i--)
        // {
        //     if (ms[i] != '#')
        //         s += ms[i];
        // }
        // cout << s << "\n";
    }

    return 0;
}