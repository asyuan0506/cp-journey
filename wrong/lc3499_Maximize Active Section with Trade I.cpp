class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) { // 010 -> 000  101 -> 111  
        int left = 0, right = 0;
        int mx = 0;
        int cnt = 0;
        s = "1" + s + "1";
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                if (left && right)
                    mx = max(mx, left + right);
                if (s[i] == s[i - 1]) continue;
                left = right;
                right = 0;
            }
            else
            {
                right++;
            }
        }
        return cnt + mx - 1;

    }
};