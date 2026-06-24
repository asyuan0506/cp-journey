#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, n1, n2;
    cin >> N;
    char a, b;
    while (N--)
    {
        int M;
        cin >> M;
        /* FASTER
        string s1 = "", s2 = "";
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b;
            s1 += a;
            s2 += b;
        }
        int carry = 0; // Maybe use int will faster than bool
        for (int i = M - 1; i >= 0; i--)
        {
            n1 = s1[i] - '0';
            n2 = s2[i] - '0';
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            s1[i] = (tmp % 10) + '0';
        }
        cout << s1 << "\n";
        */
        vector<pair<int, int>> v(M);
        string ans = "";
        for (int i = 0; i < M; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        int carry = 0;
        for (int i = M - 1; i >= 0; i--)
        {
            v[i].first = v[i].first + v[i].second + carry;
            carry = v[i].first / 10;
            v[i].first %= 10;
            ans += (char)(v[i].first + '0'); // Never insert char at the begining of string, it is slow
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
        if (N != 0)
            cout << "\n";
    }

    return 0;
}