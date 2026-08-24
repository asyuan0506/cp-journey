#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return abs(a) < abs(b);
}

int main()
{
    int p;
    cin >> p;
    while (p--)
    {
        int f;
        cin >> f;
        vector<int> floors(f);
        for (int i = 0; i < f; i++)
        {
            cin >> floors[i];
        }
        sort(floors.begin(), floors.end(), cmp);
        /*
        int blue = 0; // start from blue
        int red = 0; // start from red
        int last_b = -1;
        int last_r = -1;
        for (int i = 0; i < f; i++)
        {
            if (last_b == -1 && floors[i] > 0)
            {
                last_b = 1;
                blue++;
            }
            else if (last_b == 1 && floors[i] < 0)
            {
                blue++;
                last_b = 0;
            }
            else if (last_b == 0 && floors[i] > 0)
            {
                blue++;
                last_b = 1;
            }
            if (last_r == -1 && floors[i] < 0)
            {
                last_r = 1;
                red++;
            }
            else if (last_r == 1 && floors[i] > 0)
            {
                red++;
                last_r = 0;
            }
            else if (last_r == 0 && floors[i] < 0)
            {
                red++;
                last_r = 1;
            }
        }
        cout << max(blue, red) << "\n";
        */
       int ans = 1;
       bool last = floors[0] > 0;
       for (int i = 1; i < f; i++)
       {
            if (last == true && floors[i] < 0)
            {
                last = false;
                ans++;
            }
            else if (last == false && floors[i] > 0)
            {
                last = true;
                ans++;
            }
       }
       cout << ans << "\n";
    }

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// bool cmp(pair<int, int> a, pair<int, int> b)
// {
//     return a.first > b.first;
// }

// int main()
// {
//     int N;
//     cin >> N;
//     while (N--)
//     {
//         int floors;
//         cin >> floors;
//         vector<pair<int, int>> v(floors);
//         for (int i = 0; i < floors; i++)
//         {
//             int floor;
//             cin >> floor;
//             if (floor < 0)
//                 v[i] = { -floor, 0 };
//             else
//                 v[i] = { floor, 1 };
//         }
//         sort(v.begin(), v.end(), cmp);
//         int mx = 0, last = -2;
//         for (int i = 0; i < floors; i++)
//         {
//             if (last != v[i].second)
//             {
//                 mx++;
//                 last = v[i].second;
//             }
//         }
//         cout << mx << "\n";
//     }

//     return 0;
// }