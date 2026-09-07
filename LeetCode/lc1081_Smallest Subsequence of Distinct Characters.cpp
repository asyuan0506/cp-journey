class Solution {
public:
    string smallestSubsequence(string s) {
        const int n = s.length();
        vector<bool> used(26, false);
        vector<int>  count(26, 0);
        for (char c : s)
            count[c - 'a']++;

        string ans = "";
        for (char c : s)
        {
            count[c - 'a']--;
            if (used[c - 'a']) continue;

            while (!ans.empty())
            {
                char last = ans.back();
                if (c >= last || count[last - 'a'] <= 0) break;
                ans.pop_back();
                used[last - 'a'] = false;
            }

            ans += c;
            used[c - 'a'] = true;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (used[s[i] - 'a']) continue;
            
        //     bool appear_again = true;
        //     while (appear_again && !ans.empty() && s[i] < ans.back()) // Keep the lexicographical order smaller first.
        //     {
        //         char last = ans.back();
        //         appear_again = false;
        //         for (int j = i + 1; j < n; j++)
        //         {
        //             if (s[j] == last) // Appear again later
        //             {
        //                 ans.pop_back(); // Delete this char
        //                 used[last - 'a'] = false;
        //                 appear_again = true;
        //                 break;
        //             }
        //         }
        //     }
            
        //     ans += s[i];
        //     used[s[i] - 'a'] = true;
        // }
        return ans;
    }
};