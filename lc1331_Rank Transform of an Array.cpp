class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        if (n == 0) return arr;

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int rank = 1;
        unordered_map<int, int> ranks;
        ranks[sorted[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            if (sorted[i] != sorted[i - 1])
                ranks[sorted[i]] = ++rank;
        } 
        for (int i = 0; i < n; i++)
            arr[i] = ranks[arr[i]];
        return arr;
    }
};