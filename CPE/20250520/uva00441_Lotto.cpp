#include <bits/stdc++.h>

using namespace std;

void DFS(int idx, vector<int> &s, vector<int> now)
{
    if (now.size() == 6)
    {
        for (int i = 0; i < 5; i++)
            cout << now[i] << " ";
        cout << now[5] << "\n";
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        now.push_back(s[i]);
        DFS(i + 1, s, now);
        now.pop_back();
    }
}

int main()
{
    int k;
    bool first = true;
    while (cin >> k && k != 0)
    {
        if (!first)
            cout << "\n";
        first = false;
        vector<int> s(k);
        for (int i = 0; i < k; i++)
            cin >> s[i];
        vector<int> now;
        DFS(0, s, now);
    }

    return 0;
}