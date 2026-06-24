#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int streak = 0;
        int gain = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            gain += tmp;
            if (gain < 0)
                gain = 0;
            else
                streak = max(streak, gain);
        }
        if (streak == 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << streak << ".\n";
    }

    return 0;
}