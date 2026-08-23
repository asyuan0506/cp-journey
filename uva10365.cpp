#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int cubes;
        cin >> cubes;
        int mn = INT_MAX;
        for (int width = 1; width <= cubes; width++)
        {
            for (int length = cubes / width; length >= 1; length--)
            {
                int height = cubes / width / length;
                if (width * length * height != cubes) continue;
                mn = min(mn, 2 * width * length + 2 * width * height + 2 * length * height);   
            }
        }
        cout << mn << "\n";
    }

    return 0;
}