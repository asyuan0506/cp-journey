static int F[100];
class Solution {
public:
    static void buildF(string &t)
    {
        const int n = t.length();
        F[0] = -1;
        for (int i = 1, pos = -1; i < n; i++)
        {
            while (~pos && t[i] != t[pos + 1])
                pos = F[pos];
            if (t[i] == t[pos + 1])
                pos++;
            F[i] = pos;
        }
    }
    static int match(string &s, string &t)
    {
        const int sz = s.size();
        const int tz = t.size();
        buildF(t);
        for (int i = 0, pos = -1; i < sz; i++)
        {
            while (~pos && s[i] != t[pos + 1])
                pos = F[pos];
            if (s[i] == t[pos + 1])
                pos++;
            if  (pos + 1 == tz)
                return 1;
        }
        return 0;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        // int ans = 0;
        // const int len = word.size();
        // for (string s : patterns)
        // {
        //     if (word.find(s) < len) // word.find(s) < string::npos
        //         ans++;
        // }
        // return ans;
        int ans = 0;
        for (string &t : patterns)
        {
            ans += match(word, t);
        }
        return ans;
    }
};