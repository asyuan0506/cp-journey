#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, n;
        cin >> n >> m;
        vector<pair<string, int>> dna(m);
        for (int i = 0; i < m; i++)
        {
            cin >> dna[i].first;
            dna[i].second = 0;
            for (int j = 0; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (dna[i].first[j] > dna[i].first[k])
                        dna[i].second++;
                }
            }
        }
        stable_sort(dna.begin(), dna.end(), cmp);
        for (int i = 0; i < m; i++)
        {
            cout << dna[i].first << endl;
        }
    }
    return 0;
}