#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        int cur_max = -150005;
        int diff = -150005;
        while (n--)
        {
            int score;
            cin >> score;
            diff = max(diff, cur_max - score);
            cur_max = max(cur_max, score);
        }
        cout << diff << "\n";
    }

    return 0;
}