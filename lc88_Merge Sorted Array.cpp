class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* Time: O(m + n), Space: O(n)
        if (nums2.size() == 0)
            return;
        queue<int> q1;
        int idx2 = 0;
        for (int i = 0; i < m + n; i++)
        {
            if (i < m)
                q1.push(nums1[i]);
            if (q1.empty())
            {
                nums1[i] = nums2[idx2];
                idx2++;
                continue;
            }
            if (idx2 == n)
            {
                nums1[i] = q1.front();
                q1.pop();
                continue;
            }
            if (q1.front() > nums2[idx2])
            {
                nums1[i] = nums2[idx2];
                idx2++;
            }
            else
            {
                nums1[i] = q1.front();
                q1.pop();
            }
        } */
        int idx  = m + n - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;
        while (idx2 >= 0)
        {
            if (idx1 >= 0 && nums1[idx1] >= nums2[idx2])
                nums1[idx--] = nums1[idx1--];
            else
                nums1[idx--] = nums2[idx2--];
        }
    }
};