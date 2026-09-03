#include <bits/stdc++.h>

using namespace std;

void print(stack<char> &buffer)
{
    while(!buffer.empty())
    {
        cout << buffer.top();
        buffer.pop();   
    }
}
int main()
{
    string s;
    while (getline(cin, s))
    {
        stack<char> buffer;
        for (char c : s)
        {
            if (c == ' ')
            {
                print(buffer);
                cout << c;
            }
            else
                buffer.push(c);
        }
        if (!buffer.empty())
            print(buffer);
        cout << "\n";
    }

    return 0;
}