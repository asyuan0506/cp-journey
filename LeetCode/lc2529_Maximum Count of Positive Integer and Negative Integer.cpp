// Binary Search
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > 0)
            {
                if (mid - 1 < 0 || nums[mid - 1] < 0)
                    break;
                right = mid - 1; // 要 -1
            }
            else if (nums[mid] < 0)
            {
                if (mid + 1 == nums.size() || nums[mid + 1] > 0)
                    break;
                left = mid + 1; // 要 +1
            }
            else if (nums[mid] == 0)
            {
                break;
            }
        }
        left = mid;
        right = mid;
        while (true)
        {
            bool break_or_not = true;
            if (left != 0 && nums[left] >= 0)
            {
                left--;
                break_or_not = false;
            }
            if (right != nums.size() - 1 && nums[right] <= 0)
            {
                right++;
                break_or_not = false;
            }
            if (break_or_not)
                break;
        }
        int neg_cnt = (nums[left] < 0) ? left + 1 : 0;
        int pos_cnt = (nums[right] > 0) ? nums.size() - right : 0;
        return max(neg_cnt, pos_cnt);
    }
};
/*
此程式欠缺優化，應該還可以再更簡潔，再寫的時候是看別人教學才知道 left 和 right 要加一
和減一
*/