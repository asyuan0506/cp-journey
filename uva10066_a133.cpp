#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int N1, N2;
    while (cin >> N1 >> N2)
    {
        if (N1 == 0 && N2 == 0)
            break;
        cout << "Twin Towers #" << ++cnt << "\n";
        vector<int> t1(N1 + 1); // empty for index 0
        vector<int> t2(N2 + 1);
        for (int i = 1; i <= N1; i++)
            cin >> t1[i];
        for (int i = 1; i <= N2; i++)
            cin >> t2[i];
        vector<vector<int>> lcs(N1 + 1, vector<int>(N2 + 1, 0));
        for (int i = 1; i <= N1; i++)
        {
            for (int j = 1; j <= N2; j++)
            {
                if (t1[i] == t2[j])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        cout << "Number of Tiles : " << lcs[N1][N2] << "\n\n";
    }

    return 0;
}