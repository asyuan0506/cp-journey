class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        const int n = word1.length(), m = word2.length();
        vector<int> last(m, -1); // Find last index j that word2[i] == word1[j] && suffix that complete word2[i...]
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (j >= 0 && word1[i] == word2[j])
            {
                last[j] = i;
                j--;
            }
        }

        vector<int> res(m);
        j = 0;
        bool skipped = false;
        for (int i = 0; i < n; i++)
        {
            if (j == m) break;
            if (word1[i] == word2[j])
            {
                res[j++] = i;
                continue;
            }
            if (!skipped && (j == m - 1 || i < last[j + 1])) // If word2[j + 1...] can be completed after i index -> skip word2[j] 
            {
                skipped = true;
                res[j++] = i;
            }
        }
        return (j == m) ? res : vector<int>();
    }
};