class Solution {
public:
    // static bool cmp(vector<int> &a, vector<int> &b)
    // {
    //     if (a[0] == b[0])
    //         return a[1] > b[1];
    //     return a[0] < b[0];
    // }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), cmp);
        ranges::sort(intervals, less<pair<int, int>>{}, [](vector<int>& x) {
            return pair{x[0], -x[1]}; // Ascending order, if begin at same point, larger end first(-x[1])
        });
        int remain = intervals.size();
        int right = 0;
        for (vector<int> &i : intervals)
        {
            if (i[1] <= right)
                remain--;
            else
                right = i[1];
        }
        return remain;
    }
};