class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 2; i <= 9; i++) 
        { // Each digit in the number is one more than the previous digit; therefore, enumerate each digit.
            for (int j = 1; j <= 10 - i; j++)
            {
                int num = 0;
                for (int k = j; k < (j + i); k++)
                {
                    num = num * 10 + k;
                }
                if (num < low) continue;
                if (num > high) break;
                ans.push_back(num);
            }
        }
        return ans;
    }
};