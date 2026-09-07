class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        
        int i = 0, j = 0, n = s.length();  // i: replaced, j: not change
        for (char c : t) {
            if (s[i] == c) i++;
            else
                i = max(i, j + 1); // Jump this char
            if (s[j] == c) j++;
            if (i == n) return true;
        }
        return false;
    }
};