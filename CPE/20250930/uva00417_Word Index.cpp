#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

void init()
{
    queue<string> q;
    for (char c = 'a'; c <= 'z'; c++)
    {
        string tmp = string(1, c);
        q.push(tmp);
        ans.push_back(tmp);
    }
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        if (s.length() == 5) break;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (s.back() >= c) continue;
            string temp = s + c;
            q.push(temp);
            ans.push_back(temp);
        }
    }
}

int main()
{
    init();
    string word;
    while (cin >> word)
    {
        auto it = find(ans.begin(), ans.end(), word);
        if (it == ans.end())
            cout << "0\n";
        else
            cout << it - ans.begin() + 1 << "\n";
    }

    return 0;
}