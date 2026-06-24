#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1;
    int Case = 1;
    while (getline(cin, s1)) // use getline because space also count
    {
        if (s1 == "#")
            break;
        string s2;
        getline(cin, s2);

        const int len1 = s1.size();
        const int len2 = s2.size();
        vector<vector<int>> lcs(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        cout << "Case #" << Case++ << ": you can visit at most " << lcs[len1][len2] << " cities.\n";
    }

    return 0;
}