#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        vector<vector<int>> m(n, vector<int> (n));
        vector<vector<int>> sum(n, vector<int> (2, 0)); // 0: row
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
                tmp += m[i][j];
            }
            sum[i][0] = tmp;
        }
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            for (int i = 0; i < n; i++)
            {
                tmp += m[i][j];
            }
            sum[j][1] = tmp;
        }
        int status = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum[i][0] % 2 || sum[i][1] % 2)
            {
                status = 1;
                break;
            }
        }
        int change[2];
        bool used = false;
        for (int i = 0; i < n; i++)
        {
            if (used) break;
            for (int j = 0; j < n; j++)
            {
                if (sum[i][0] % 2 && sum[j][1] % 2)
                {
                    change[0] = i; change[1] = j;
                    sum[i][0]++; sum[j][1]++;
                    used = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (sum[i][0] % 2 || sum[i][1] % 2)
            {
                status = 2;
                break;
            }
        }
        if (status == 0)
            cout << "OK\n";
        else if (status == 1)
            cout << "Change bit (" << change[0]+1 << "," << change[1]+1 << ")\n";
        else if (status == 2)
            cout << "Corrupt\n";
    }

    return 0;
}