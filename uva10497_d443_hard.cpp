#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> visited(801);


vector<int> add(vector<int> a, vector<int> b)
{
    if (b.size() > a.size())
        swap(a, b);
    bool carry = false;
    for (int i = 0; i < b.size(); i++)
    {
        a[i] += b[i] + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if (carry)
    {
        if (a.size() == b.size())
            a.push_back(1);
        else
        {
            for (int i = b.size(); i < a.size() && carry; i++)
            {
                a[i] += carry;
                carry = a[i] / 10;
                a[i] %= 10;
            }
            if (carry)
                a.push_back(1);
        }
    }
    return a;
}

vector<int> mul(vector<int> a, vector<int> b)
{
    vector<int> result(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            result[i + j] += a[i] * b[j];
    int carry = 0;
    for (int i = 0; i < result.size(); i++)
    {
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    return result;
}

vector<int> per(int n)
{
    if (!visited[n].empty())
        return visited[n];
    vector<int> tmp;
    int n_tmp = n - 1;
    while (n_tmp > 0)
    {
        tmp.push_back(n_tmp % 10);
        n_tmp /= 10;
    }
    visited[n] = mul(tmp, add(per(n - 1), per(n - 2)));
    return visited[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    visited[1] = vector<int> (1, 0);
    visited[2] = vector<int> (1, 1);
    int n;
    while (cin >> n && n != -1)
    {
        vector<int> ans = per(n);
        bool zero = true;
        for (int i = ans.size() - 1; i >= 0; i--)
            if (ans[i] != 0 || !zero)
            {
                zero = false;
                cout << ans[i];
            }
        if (zero)
            cout << 0;
        cout << "\n";
    }

    return 0;
}