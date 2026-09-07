class Solution
{
public:
    int countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        // double rat = double(a) / double(b);
        const int n = nums.size();
        int valid = 0;
        for (int i = 0; i < n; i++)
        {
            int odd = 0, even = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2)
                    odd++;
                else
                    even++;
                // double ratio = double(even) / double(odd);
                // if (odd > 0 && ratio <= rat) valid++;
                if (odd > 0 && (even * b <= a * odd))
                    valid++;
            }
        }
        return valid;
    }
};