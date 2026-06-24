#include <bits/stdc++.h>

using namespace std;

bool yield23(vector<int> &v, int idx, int val)
{
    if (idx == 5)
    {
        if (val == 23)
            return true;
        else
            return false;
    }
    return yield23(v, idx + 1, val + v[idx]) ||
           yield23(v, idx + 1, val - v[idx]) ||
           yield23(v, idx + 1, val * v[idx]);
}

int main()
{
    vector<int> tuple(5);
    while (true)
    {
        bool all_zero = true;
        for (int i = 0; i < 5; i++)
        {
            cin >> tuple[i];
            if (tuple[i] != 0)
                all_zero = false;
        }
        if (all_zero)
            break;  
        
        sort(tuple.begin(), tuple.end()); // Need to sort the vector to use next_permutation

        bool possible = false;
        do
        {
            if (yield23(tuple, 1, tuple[0]))
                possible = true;
            if (possible)
                break;
        } while (next_permutation(tuple.begin(), tuple.end()));
        

        if (possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}