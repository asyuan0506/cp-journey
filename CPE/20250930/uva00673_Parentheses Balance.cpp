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
        stack<char> buffer;
        bool balance = true;
        for (char c : s)
        {
            if (c == ')')
            {
                if (buffer.empty() || buffer.top() != '(')
                {
                    balance = false;  
                    break;
                }
                buffer.pop();
            }
            else if (c == ']')
            {
                if (buffer.empty() || buffer.top() != '[')
                {
                    balance = false;
                    break;
                }
                buffer.pop();
            }
            else
                buffer.push(c);
        }
        if (!buffer.empty() || !balance)
        {
            balance = false;
            cout << "No\n";
        }
        if (balance)
            cout << "Yes\n";
    }


    return 0;
}