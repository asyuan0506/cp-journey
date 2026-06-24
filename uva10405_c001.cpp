#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2))
    {
        const int len1 = s1.size();
        const int len2 = s2.size();
        vector<vector<int>> lcs(len1 + 1, vector<int> (len2 + 1, 0));
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (s1[i] == s2[j])
                    lcs[i + 1][j + 1] = lcs[i][j] + 1;
                else
                    lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
            }
        }
        cout << lcs[len1][len2] << "\n";
    }
    
    return 0;
}