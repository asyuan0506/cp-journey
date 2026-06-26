class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0; 
        const int s_size = s.size();
        if (s_size == 0) return true;
        for (int i = 0; i < t.size(); i++) {
            if (s[idx] == t[i]) {   // follow "s" sequence, because not every alphabets in t it will true
                idx++;
                if (idx == s_size) return true;
            }
        }

        return false;
    }
};

class Solution {   // Two pointer solution
public:
    bool isSubsequence(string s, string t) {
        int sp = 0;
        int tp = 0;

        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }

        return sp == s.length();        
    }
};
