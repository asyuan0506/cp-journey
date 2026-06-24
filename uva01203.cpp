#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> r(3001);
    string reg;
    while (cin >> reg && reg != "#")
    {
        int qnum, p;
        cin >> qnum >> p;
        r[p].push_back(qnum);
    }
    int k;
    cin >> k;
    int time = 0;
    set<int> ans;
    while (++time && k > 0)
    {
        for (int i = 1; i <= 3000; i++)
        {
            if (time % i == 0)
            {
                for (auto j : r[i])
                    ans.insert(j);
            }
        }
        for (auto j : ans)
        {
            cout << j << "\n";
            k--;
            if (k == 0)
                return 0;
        }
        ans.clear();
    }

    return 0;
}