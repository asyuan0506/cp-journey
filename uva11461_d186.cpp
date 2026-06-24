//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // vector<int> sq_num;
    // sq_num.push_back(1);
    // for (int i = 2; i * i <= 100005; i++)
    // {
    //     sq_num.push_back(i * i);
    // }

    // int a, b;
    // while (cin >> a >> b && (a + b != 0))
    // {
    //     int n = 0;
    //     for (auto i = lower_bound(sq_num.begin(), sq_num.end(), a); i != sq_num.end() && *i <= b; i++)
    //         n++;
    //     cout << n << "\n";
    // }
    int a, b;
    while (cin >> a >> b && a + b)
    {
        int n1 = ceil(sqrt(a));
        int n2 = floor(sqrt(b));
        cout << n2 - n1 + 1 << "\n";
    }

    return 0;
}