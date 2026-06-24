#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> sentences;
    string s;
    int longest = 0;
    while (getline(cin, s))
    {
        sentences.push_back(s);
        longest = max(longest, (int)s.size());
    }

    for (int i = 0; i < longest; i++)
    {
        for (int j = sentences.size() - 1; j >= 0; j--)
        {
            if (sentences[j].size() <= i)
            {
                cout << " ";
                continue;
            }
            cout << sentences[j][i];
        }
        cout << "\n";
    }
    
    return 0;
}