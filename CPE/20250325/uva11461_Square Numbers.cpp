#include <bits/stdc++.h>

using namespace std;

const int max_n = 100005;
bool square_num[max_n];

int main()
{ 
    memset(square_num, false, max_n);
    for (int i = 1; i < sqrt(max_n); i++)
    {
        square_num[i * i] = true; 
    }
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
    {
        int res = 0;
        for (int i = a; i <= b; i++)
            if (square_num[i])
                res++;
        cout << res << "\n";
    }

    return 0;
}