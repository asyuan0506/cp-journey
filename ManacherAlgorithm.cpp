// https://segmentfault.com/a/1190000003914228#articleHeader3

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> RL(2 * s.size() + 1, 0);
    string m_s = "#";
    for (char c : s)
    {
        m_s += c;
        m_s += '#';
    }

    int max_right = 0;
    int mirror = 0;
    int max_len = 0;
    for (int i = 0; i < m_s.size(); i++)
    {
        if (i < max_right)
            RL[i] = min(RL[2 * mirror - i], max_right - i);
        else
            RL[i] = 1;
        while (i - RL[i] >= 0 && i + RL[i] < m_s.size() && m_s[i - RL[i]] == m_s[i + RL[i]])
            RL[i]++;
        if (i + RL[i] - 1 > max_right)
        {
            mirror = i;
            max_right = i + RL[i] - 1;
        }
        max_len = max(max_len, RL[i] - 1);
    }
    cout << max_len << endl;

    return 0;
}