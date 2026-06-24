/*
    c039.cpp
    UVa Online Judge
    3n + 1 problem
    Solution:
        Just Brute Force
*/
#include <iostream>

using namespace std;

int cycle_length(long long x)
{
    if (x == 1)
        return 1;
    if (x % 2 == 0)
        return 1 + cycle_length(x / 2);
    return 1 + cycle_length(3 * x + 1);
}

int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        int max_cycle_length = 0;
        cout << i << " " << j << " ";
        if (i > j)
        {
            int tmp = i;
            i = j;
            j = tmp;
        }
        for (i; i <= j; i++)
        {
            max_cycle_length = max(max_cycle_length, cycle_length(i));
        }
        cout << max_cycle_length << endl;
    }

    return 0;
}