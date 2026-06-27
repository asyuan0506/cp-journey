/*
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int, int> m;
        sort(nums.begin(), nums.end());
        for (int num : nums)
        {
            m[num]++;
            used[num] = false;
        }
        int ans = 0;
        const int upper = sqrt(INT_MAX);
        for (int num : nums)
        {
            if (used[num])
                continue;
            if (num == 1)
            {
                ans = max(ans, (m[1] + 1) / 2); // y = 2x - 1 -> x = (y + 1) / 2
                used[1] = true;
                continue;
            }
            int tmp = num;
            int cnt = 0;
            while (tmp <= INT_MAX)
            {
                if (m[tmp] >= 1)
                {
                    cnt++;
                    ans = max(ans, cnt);
                    used[tmp] = true;
                }
                if (m[tmp] < 2 || tmp > upper)
                    break;
                tmp *= tmp;
            }
        }
        return 2 * ans - 1;
    }
};
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums)
        {
            m[num]++;
        }
        int ans = (m[1] % 2) ? m[1] : m[1] - 1; // Handle 1 seperately
        const int upper = 31622; // sqrt(10^9)
        for (auto& i : m)
        {
            if (i.first == 1)
                continue;
            int tmp = i.first;
            int cnt = 0;
            while (m.count(tmp) && m[tmp] >= 2 && tmp <= upper)
            {
                cnt += 2;
                tmp *= tmp;
            }
            if (m.count(tmp))
                cnt++;
            else
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};