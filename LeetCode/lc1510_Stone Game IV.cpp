constexpr int max_n = 100005;
class Solution {
public:
    inline static vector<bool> dp;
    inline static bool init = [](){
        dp.assign(max_n, false);

        for (int i = 0; i < max_n; i++)
        {
            if (dp[i]) continue;
            for (int j = 1; j < max_n; j++)
            {
                int nxt = i + j * j;
                if (nxt >= max_n) break;
                dp[nxt] = true;
            }
        }
        return false;
    }();
    bool winnerSquareGame(int n) {
        return dp[n];
    }
};