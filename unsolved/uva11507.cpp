#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L;
    while (cin >> L && L)
    {
        int y = 0, z = 0;
        for (int i = 0; i < L - 1; i++)
        {
            string op;
            cin >> op;
            if (op == "No")
                continue;
            if (op[1] == 'z')
            {
                if (op[0] == '+')
                    z++;
                else
                    z--;
            }
            else if (op[1] == 'y')
            {
                if (op[0] == '+')
                    y++;
                else
                    y--;
            }
        }
        cout << y << " " << z << "\n";
    }

    return 0;
}