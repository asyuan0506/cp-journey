#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans[500001];
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= 500000; i++)
    {
        ans[i] = ans[i - 1] + 2;
        if (ans[i] > i)
            ans[i] = 2;
    }
    while (cin >> n && n != 0)
    {
        cout << ans[n] << "\n";
    }

    return 0;
}
