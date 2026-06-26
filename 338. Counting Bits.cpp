class Solution {    // divide to [0], [1], [2 ~ 3], [4 ~ 7] look its size before and add 1
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int cur_size = 1;
        for (int i = 1; i <= n; i++) {
            if (cur_size * 2 == i) cur_size *= 2;   // switching size because binary format added one digit
            ans[i] = ans[i - cur_size] + 1;
        }
        return ans;
    }
};

// Worse solution
class Solution {                        // divide to [2 ~ 3], [4 ~ 7], [8 ~ 15] and write its binary format, watch the relationship
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        if (n == 0) return ans; 
        ans[1] = 1;
        if (n == 1) return ans;
        ans[2] = 1; 
        if (n == 2) return ans;
        ans[3] = 2;
        if (n == 3) return ans;
        int pre_size = 2; int cycle = 0;
        for (int i = 4; i <= n; i++) {           
            if (cycle < pre_size) {        // Look pre_size before, when it cycled, look pre_size before and add 1
                ans[i] = ans[i - pre_size];
                cycle++;
            }
            else {
                ans[i] = ans[i - pre_size] + 1;
                cycle++;
                if (cycle == pre_size * 2) {
                    cycle = 0;
                    pre_size *= 2;
                }
            }
        }
        return ans;
    }
};
