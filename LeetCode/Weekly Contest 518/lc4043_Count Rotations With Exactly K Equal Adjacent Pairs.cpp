class Solution {
public:
    int countRotations(string s, int k) {
        const int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string left, right;
            for (int j = 0; j < i; j++)
            {
                right += s[j];
            }
            for (int j = i; j < n; j++)
            {
                left += s[j];
            }
            int sum = 0;
            string s2 = left + right;
            for (int j = 0; j < n - 1; j++)
            {
                if (s2[j] == s2[j + 1])
                    sum++;
            }
            if (sum == k)
                ans++;
        }
        return ans;
    }
};