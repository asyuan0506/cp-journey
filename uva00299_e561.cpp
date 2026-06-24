// Bubble Sort
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int c;
    while (N--)
    {
        cin >> c;
        vector<int> cars(c);
        for (int i = 0; i < c; i++)
            cin >> cars[i];
        
        int swap_cnt = 0;
        for (int i = 0; i < c; i++)
        {
            for (int j = c - 1; j > i; j--)
            {
                if (cars[j - 1] > cars[j])
                {
                    int tmp = cars[j];
                    cars[j] = cars[j - 1];
                    cars[j - 1] = tmp;
                    swap_cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swap_cnt << " swaps.\n";

    }

    return 0;
}