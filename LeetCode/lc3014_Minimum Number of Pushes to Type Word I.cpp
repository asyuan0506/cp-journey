class Solution {
public:
    // static bool cmp(int& a, int& b) 
    // {
    //     return a > b;
    // }
    int minimumPushes(string word) {
        // vector<int> freq(26);
        // for (char c : word)
        //     freq[c - 'a']++;
        // sort(freq.begin(), freq.end(), cmp);

        // int ans = 0;
        // for (int i = 0; i < 26; i++)
        //     ans += (i / 8 + 1) * freq[i]; // Greedy

        // return ans;
        
        // All letters in word are distinct
        // int q = word.size() / 8;
        int q = word.size() >> 3;
        // 8 * (1 + 2 +... q) + remainder * (q + 1)
        // return 4 * (1 + q) * q + (q + 1) * (word.size() % 8);
        // (q + 1) * (4q + r)
        // 7 = 0111, so a % 8 = a & 7
        return (q + 1) * ((q << 2) + (word.size() & 7)); 

    }
};