#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        
        // int cnt_m = 0, cnt_f = 0;
        // for (char c : s)
        // {
        //     if (c == 'M')
        //         cnt_m++;
        //     else if (c == 'F')
        //         cnt_f++;
        // }
        // if (cnt_m == cnt_f && !(cnt_m == 1 && cnt_f == 1))
        //     cout << "LOOP\n";
        // else
        //     cout << "NO LOOP\n";
        stringstream ss;
        ss << s;
        int len = 0;
        int cnt_m = 0, cnt_f = 0;
        string tmp;
        while (ss >> tmp)
        {
            len++;
            for (char c : tmp)
            {
                if (c == 'M')
                    cnt_m++;
                else if (c == 'F')
                    cnt_f++;
            }
        }
        if (len > 1 && cnt_m == cnt_f)
            cout << "LOOP\n";
        else
            cout << "NO LOOP\n";
    }

    return 0;
}