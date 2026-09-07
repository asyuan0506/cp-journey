#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int Case = 0;
    while (cin >> n)
    {
        vector<int> nums(n);
        unordered_map<int, bool> visited;
        bool b2 = true;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] <= last) b2 = false;
            last = nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (!b2) break;
            for (int j = i; j < n; j++)
            {
                int sum = nums[i] + nums[j];
                if (visited[sum])
                {
                    b2 = false;
                    break;
                }
                visited[sum] = true;
            }
        }
        if (b2) 
            cout << "Case #" << ++Case << ": It is a B2-Sequence.\n\n";
        else
            cout <<  "Case #" << ++Case << ": It is not a B2-Sequence.\n\n";
    }

    return 0;
}