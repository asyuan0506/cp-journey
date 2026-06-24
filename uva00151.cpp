#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
            return 0;

        int m = 0; // brute force from 1
        while (++m)
        {
            vector<int> region(N);
            for (int i = 1; i <= N; i++)
            {
                region[i - 1] = i;
            }

            int off_region = 0; // Start from 1
            for (int i = 1; i < N; i++)
            { // Turn off each region need N times, last one for checking if it's region 13
                region.erase(region.begin() + off_region);
                off_region = (off_region + m - 1) % region.size(); // Minus 1 because we already erased one region
            }
            if (region[0] == 13)
            {
                cout << m << endl;
                break;
            }
        }
    }

    return 0;
}