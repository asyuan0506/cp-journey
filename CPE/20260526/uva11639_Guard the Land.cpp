#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int Night = 0;
    while (T--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<vector<int>> mp(100, vector<int> (100, 0));
        for (; x1 < x2; x1++)
            for (int j = y1; j < y2; j++)
                mp[x1][j]++;
        cin >> x1 >> y1 >> x2 >> y2;
        for (; x1 < x2; x1++)
            for (int j = y1; j < y2; j++)
                mp[x1][j]++;
        
        vector<int> region(3, 0);
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                region[mp[i][j]]++;
        cout << "Night " << ++Night << ": ";
        cout << region[2] << " " << region[1] << " " << region[0] << "\n";

    }

    return 0;
}