#include <bits/stdc++.h>

using namespace std;

void helper(string s, vector<int>& v, int n)
{
    v.resize(n + 1);
    int cur = 1, pos;
    stringstream ss(s);
    while (ss >> pos)
    {
        v[pos] = cur++;
    }
}

int main()
{
    string s;
    int n;
    vector<int> c;
    while (getline(cin, s))
    {
        if (s.length() <= 2)
        {
            n = 0;
            c.clear();
            for (char c : s)
                n = n * 10 + (c - '0');
            getline(cin, s);
            helper(s, c, n);
            continue;
        }
        vector<int> rank;
        helper(s, rank, n);
        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (c[i] == rank[j])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        cout << lcs[n][n] << "\n";
    }

    return 0;
}