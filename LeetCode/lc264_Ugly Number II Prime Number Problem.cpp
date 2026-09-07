class Solution {
public:
    long long my_pow(int num, int &times) {
        long long out = 1;
        for (int i = 0; i < times; i++) out *= num;
        return out;
    }
    int nthUglyNumber(int n) {
        vector<int> result;
        for (int i = 0; i < 33; i++) {
            long long two = my_pow(2, i);
            for (int j = 0; j < 21; j++) {
                long long three = my_pow(3, j);
                long long tmp = two * three;
                if (tmp > INT_MAX) break;
                for (int k = 0; k < 14; k++) {
                    long long tmp_2 = tmp * my_pow(5, k);
                    if (tmp_2 > INT_MAX) break;
                    result.push_back(tmp_2);
                }
            }
        }
        sort(result.begin(), result.end());
        return result[n - 1];
    }
};
// 基本上就是爆開，然後再確認有沒有超出INT_MAX
