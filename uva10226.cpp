#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool first = true;
    int N;
    cin >> N;
    cin.ignore();
    string blank;
    getline(cin, blank);
    string s;
    while(N--)
    {
        if (!first)
            cout << "\n";
        first = false;
        int total = 0;
        map<string, int> cnt;
        while (getline(cin, s))
        {
            if (s == "") break;
            cnt[s]++;
            total++;
        }
        for (auto i : cnt)
        {
            float percent = (float)i.second / (float)total * 100; 
            cout << i.first << " ";
            cout << setprecision(4) << fixed << percent << "\n";
        }
    }

    return 0;
}