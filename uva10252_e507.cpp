// Just count the same alphabet

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    while (getline(cin, s1))
    {
        getline(cin, s2);
        vector<int> cnt1(26, 0);
        for (char c : s1)
            cnt1[c - 'a']++;
        vector<int> cnt2(26, 0);
        for (char c : s2)
        {
            if (cnt1[c - 'a'] > 0)
            {
                cnt2[c - 'a']++;
                cnt1[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            char c = i + 'a';
            while (cnt2[i] > 0)
            {
                cnt2[i]--;
                cout << c;
            }
        }
        cout << "\n";
    }

    return 0;
}