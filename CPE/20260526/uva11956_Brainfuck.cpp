#include <bits/stdc++.h>

using namespace std;

char my_hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    int T;
    cin >> T;
    int Case = 0;
    while (T--)
    {
        string s;
        cin >> s;
        cout << "Case " << ++Case << ": ";
        vector<int> bytes(100, 0);
        int ptr = 0;
        for (char c : s)
        {
            if (c == '>')
            {
                ptr = (ptr + 1) % 100;
            }
            else if (c == '<')
            {
                ptr--;
                if (ptr < 0)
                    ptr = 99;
            }
            else if (c == '+')
            {
                bytes[ptr] = (bytes[ptr] + 1) % 256;
            }
            else if (c == '-')
            {
                bytes[ptr]--;
                if (bytes[ptr] < 0)
                    bytes[ptr] = 255;
            }
        }
        for (int i = 0; i < 100; i++)
        {
            cout << my_hex[bytes[i] / 16] << my_hex[bytes[i] % 16];
            if (i != 99) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}