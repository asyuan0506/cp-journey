#include <bits/stdc++.h>

using namespace std;

vector<string> dic;
unordered_map<string, int> mp;

vector<int> BFS(string q1, string q2)
{
    queue<int> q;
    q.push(mp[q1]);
    vector<int> parents(dic.size(), -1); // Use parents instead of record every path
    parents[mp[q1]] = -2;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < dic[cur].length(); i++) // For every char, find doublets word (possible words: 26 * length of word)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                string s = dic[cur];
                s[i] = c;
                if (mp.find(s) != mp.end() && parents[mp[s]] == -1)
                {
                    parents[mp[s]] = cur;
                    if (s == q2)
                        return parents;
                    q.push(mp[s]);
                }
            }
        }
    }
    return parents;
}

int main()
{ 
    string s;
    while (getline(cin, s) && !s.empty())
    {
        mp[s] = dic.size();
        dic.push_back(s);
    }

    string q1, q2;
    bool first = true;
    while (cin >> q1 >> q2)
    {
        if (!first)
            cout << "\n";
        first = false;
        if (mp.find(q1) == mp.end() || mp.find(q2) == mp.end()) // If not exitst in dictionary, No solution.
        {
            cout << "No solution.\n";
            continue;
        }

        vector<int> parents = BFS(q1, q2);
        if (parents[mp[q2]] == -1)
            cout << "No solution.\n";
        else
        {
            stack<int> ans;
            for (int idx = mp[q2]; idx != -2; idx = parents[idx])
            {
                ans.push(idx);
            }
            while (!ans.empty())
            {
                cout << dic[ans.top()] << "\n";
                ans.pop();
            }
        }
    }

    return 0;
}