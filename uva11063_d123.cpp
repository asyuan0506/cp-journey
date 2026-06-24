#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int Case = 0;
    while (cin >> N)
    {
        bool b2 = true;
        map<int, bool> psum;
        vector<int> nums(N);
        int cur_max = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            cin >> nums[i];
            if (cur_max >= nums[i] || nums[i] < 1)
            {
                b2 = false;
            }
            cur_max = nums[i];
        }
        for (int i = 0; i < N; i++)
        {
            int tmp = nums[i];
            for (int j = 0; j <= i; j++)
            {
                int sum = nums[j] + tmp;
                if (psum[sum] == true)
                {
                    b2 = false;
                    break;
                }
                psum[sum] = true;
            }
            if (!b2)
                break;
        }
        if (b2)
            cout << "Case #" << ++Case << ": It is a B2-Sequence.\n\n";
        else
            cout << "Case #" << ++Case << ": It is not a B2-Sequence.\n\n";
    }

    return 0;
}