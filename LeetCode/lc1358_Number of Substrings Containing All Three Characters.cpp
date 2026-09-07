class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.length();
        int ans = 0;
        int last[3] = {-1, -1, -1};
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
            ans += min({last[0], last[1], last[2]}) + 1;
        }        

        return ans;
    }
};