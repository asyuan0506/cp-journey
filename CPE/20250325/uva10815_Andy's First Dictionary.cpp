#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> dic;
    string s;
    while (cin >> s)
    {
        string processed;
        for (char c : s)
        {
            if ('a' <= c && c <= 'z')
                processed += c;
            else if ('A' <= c && c <= 'Z')
                processed += c - 'A' + 'a';
            else
            {
                if (!processed.empty())
                    dic.insert(processed);
                processed = "";
            }
        }
        if (!processed.empty())
            dic.insert(processed);
    }
    for (string s : dic)
        cout << s << "\n";


    return 0;
}