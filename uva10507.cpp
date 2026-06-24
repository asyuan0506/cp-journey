#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, m;
    char c1, c2, c3;
    while (cin >> s >> m >> c1 >> c2 >> c3)
    {
        int year = 0;
        int awake_cnt = 3;
        map<int, bool> awake;
        awake[c1 - 'A'] = true;
        awake[c2 - 'A'] = true;
        awake[c3 - 'A'] = true;
        vector<vector<int>> con(26);
        for (int i = 0; i < m; i++)
        {
            char tmp_c1, tmp_c2;
            cin >> tmp_c1 >> tmp_c2;
            int ic1 = tmp_c1 - 'A';
            int ic2 = tmp_c2 - 'A';
            con[ic1].push_back(ic2);
            con[ic2].push_back(ic1);
        }
        while (true)
        {
            vector<int> next_awake;
            for (int i = 0; i < 26; i++)
            {
                if (awake[i] || con[i].size() == 0)
                    continue;
                int cnt = 0;
                for (int j : con[i])
                {
                    if (awake[j])
                    {
                        cnt++;
                        if (cnt == 3)
                        {
                            next_awake.push_back(i);
                            break;
                        }
                    }
                }
            }
            for (int i : next_awake)
            {
                awake_cnt++;
                awake[i] = true;
            }
            if (next_awake.size() > 0)
                year++;
            else
                break;
        }
        if (awake_cnt == s)
            cout << "WAKE UP IN, " << year << ", YEARS\n";
        else
            cout << "THIS BRAIN NEVER WAKES UP\n";
    }

    return 0;
}