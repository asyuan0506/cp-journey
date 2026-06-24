#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        int tmp = 1;
        int cnt = 1;
        while (tmp % N != 0)
        {
            cnt++;
            tmp %= N;
            tmp = tmp * 10 + 1;
        }
        cout << cnt << "\n";
    }
}