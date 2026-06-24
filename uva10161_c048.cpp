#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        /* Slower
        long long sq = ceil(sqrt(N));
        int xy[2] = { 1, (int)sq };
        pair<int, int> helper = make_pair(0, 1); // first: idx second: add num
        if (sq % 2 == 0)
        {
            xy[0] = (int)sq;
            xy[1] = 1;
            helper = make_pair(1, 1);
        }
        long long cur = sq * sq;
        while (cur != N)
        {
            xy[helper.first] += helper.second;
            cur--;
            if (xy[0] == xy[1]) 
            {
                helper.first = !helper.first;
                helper.second = -1;
            }
        }
        cout << xy[0] << " " << xy[1] << "\n"; 
        */
        int sq = ceil(sqrt(N));
        int mid = sq * sq - sq + 1; // mid
        int x = sq, y = sq;
        if (N > mid)
            y -= (N - mid);
        else
            x -= (mid - N);
        if (sq % 2)
            swap(x, y);
        cout << x << " " << y << "\n";
    }

    return 0;
}