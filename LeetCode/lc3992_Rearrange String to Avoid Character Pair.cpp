class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> count(26, 0);
        for (char c : s)
            {
                count[c - 'a']++;
            }
        string ans = "";
        for (int i = 0; i < count[y - 'a']; i++)
            {
                ans += y;
            }
        count[y-'a'] = 0;
        for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < count[i]; j++)
                    ans += (char)('a' + i);
            }
        return ans;
    }
};