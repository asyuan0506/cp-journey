#include <bits/stdc++.h>

using namespace std;

int cnt[10000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    multiset<int> my_set;
    while (cin >> N)
    {
        my_set.insert(N);
        int size = my_set.size();
        multiset<int>::iterator iter = my_set.begin();
        // for (int i = 0; i < size / 2; i++)
        // {
        //     iter++;
        // }
        advance(iter, size / 2);
        if (size % 2)
        {
            cout << *iter << "\n";
        }
        else
        {
            cout << (*iter + *(--iter)) / 2 << "\n";
        }
    }

    return 0;
}