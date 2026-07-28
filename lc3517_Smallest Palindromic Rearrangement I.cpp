class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        // for (char c : s)
        //     cnt[c - 'a']++;
        // string ans = "";
        // int odd_idx = -1;
        // for (int i = 0; i < 26; i++)
        // {
        //     for (int j = 0; j < cnt[i] / 2; j++)
        //         ans += ('a' + i);
        //     if (cnt[i] % 2)
        //         odd_idx = i;
        //     cnt[i] -= cnt[i] / 2;
        // }

        // if ( ~odd_idx )
        // {
        //     ans += ('a' + odd_idx);
        //     cnt[odd_idx]--;
        // }
        
        // for (int i = 25; i >= 0; i--)
        //     for (int j = 0; j < cnt[i]; j++)
        //         ans += ('a' + i);
        // return ans;

        const int n = s.length();
        for (int i = 0; i < n / 2; i++)
            cnt[s[i] - 'a']++;

        int j = 0;
        for (int i = 0; i < 26; i++)
        {
            while (cnt[i]--)
            {
                s[j] = ('a' + i);
                s[n - 1 - j] = ('a' + i);
                ++j;
            }
        }
        return s;
    }
};