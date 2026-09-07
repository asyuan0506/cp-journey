class Solution
{
public:
    long long C(int n, int r, int k)
    {
        r = min(r, n - r);
        // C(n, r) = n! / (r! * (n - r)!)
        long long res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = res * (n - r + i) / i;
            if (res >= k)
                return k;
        }
        return res;
    }
    long long Permutation(vector<int> &freq, int k)
    {
        long long used = 0;
        long long res = 1;
        for (int cnt : freq)
        {
            // used + 1 spaces, put cnt same elements into those spaces
            // x1 + x2 +... x_used+1 = cnt x_i >= 0
            // cnt - 1 + (used + 1)
            res = res * C(used + cnt, cnt, k);
            if (res >= k)
                return k; // Use this char
            used += cnt;
        }
        return res;
    }
    string smallestPalindrome(string s, int k)
    {
        const int n = s.length();
        vector<int> freq(26, 0);
        for (int i = 0; i < n / 2; i++)
            freq[s[i] - 'a']++;
        // abccba  1-st
        // acbbca  2-nd
        // baccba  3-rd
        // bcaacb  4-th
        // cabbac  5-th
        // cbaabc  6-th
        // Calculate combination from left to right, from lexicographically smallest to highest
        string ans = "";
        for (int i = 0; i < n / 2; i++)
        {
            bool found = false;
            for (int c = 0; c < 26; c++)
            {
                if (freq[c] == 0)
                    continue;

                freq[c]--;
                long long ways = Permutation(freq, k);
                if (ways >= k)
                {
                    ans += ('a' + c);
                    found = true;
                    break;
                }
                else
                {
                    freq[c]++;
                    k -= ways;
                }
            }
            if (!found)
                return "";
        }
        string right = ans;
        reverse(right.begin(), right.end());
        if (n % 2)
            ans += s[n / 2];
        return ans + right;
    }
};