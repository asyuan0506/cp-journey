// Better code: https://yuihuang.com/zj-e547/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s += '+';                 // for last char
        int x_buffer[2] = {0, 0}; // 0: left 1: right
        int cons_buffer[2] = {0, 0};
        int idx = 0;
        int oper = 1; // operator
        int tmp = 0;
        char last = -1; // handle case: 0x
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '-')
            {
                cons_buffer[idx] += tmp;
                oper = -1;
                tmp = 0;
            }
            else if (c == '+')
            {
                cons_buffer[idx] += tmp;
                oper = 1;
                tmp = 0;
            }
            else if (c == 'x')
            {
                x_buffer[idx] += tmp;
                if (tmp == 0 && last != 0)
                    x_buffer[idx] += oper;
                tmp = 0;
            }
            else if (c == '=')
            {
                cons_buffer[idx] += tmp;
                idx = 1;
                oper = 1;
                tmp = 0;
            }
            else
            {
                int num = c - '0';
                tmp = tmp * 10 + oper * num;
            }
            last = c - '0';
        }
        x_buffer[0] -= x_buffer[1];
        cons_buffer[1] -= cons_buffer[0];
        if (x_buffer[0] == 0 && cons_buffer[1] == 0)
        {
            cout << "IDENTITY\n";
        }
        else if (x_buffer[0] == 0 && cons_buffer[1] != 0)
        {
            cout << "IMPOSSIBLE\n";
        }
        else if (x_buffer[0] != 0)
        {
            int ans = floor((double)cons_buffer[1] / (double)x_buffer[0]) + 0.0; // In case of -0.0
            cout << ans << "\n";
        }
    }

    return 0;
}