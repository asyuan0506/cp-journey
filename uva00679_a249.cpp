/*
    Odd number of balls will go to left subtree
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, D, I;
    cin >> N;
    while (N--)
    {
        cin >> D >> I;
        // I--; // 0 based index MORE CONSICE
        int node_number = 1 << (D - 1); // 2 ^ (D - 1)
        for (int i = 1; i < D; i++)
        {
            if (I % 2)
            {
                I >>= 1;
                I += 1;
            }
            else
            {
                I >>= 1;
                node_number += 1 << (D - 1 - i);
            }
        }
        // int node_number = 1;
        // for (int i = 1; i < D; i++)
        // {
        //     if (I % 2) // Right
        //         node_number = node_number * 2 + 1;
        //     else
        //         node_number = node_number * 2;
        //     I = I >> 1;
        // }
        cout << node_number << "\n";
    }

    return 0;
}