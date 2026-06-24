#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s;
    string n;
    while (cin >> s >> n && (s != 0 || n != "0"))
    {
        for (int k = 0; k < n.length(); k++) // first row
        {
            char c = n[k];
            cout << " ";
            for (int i = 1; i <= s; i++)
                if (c == '0' || c == '2' || c == '3' || c >= '5')
                    cout << '-';
                else
                    cout << ' ';
            cout << ' ';
            if (k != n.length() - 1)
                cout << ' ';
        }
        cout << "\n";
        for (int i = 1; i <= s; i++)
        {
            for (int k = 0; k < n.length(); k++)
            {
                char c = n[k];
                if (c == '1' || c == '2' || c == '3' || c == '7')
                    cout << ' ';
                else
                    cout << '|';
                for (int i = 1; i <= s; i++)
                    cout << ' ';
                if (c != '5' && c != '6')
                    cout << '|';
                else
                    cout << ' ';
                if (k != n.length() - 1)
                    cout << ' ';
            }
            cout << "\n";
        }
        for (int k = 0; k < n.length(); k++)
        {
            char c = n[k];
            cout << ' ';
            for (int i = 1; i <= s; i++)
                if (c != '0' && c != '1' && c != '7')
                    cout << '-';
                else
                    cout << ' ';
            cout << ' ';
            if (k != n.length() - 1)
                cout << ' ';
        }
        cout << "\n";
        for (int i = 1; i <= s; i++)
        {
            for (int k = 0; k < n.length(); k++)
            {
                char c = n[k];
                if (c != '0' && c != '2' && c != '6' && c != '8')
                    cout << ' ';
                else
                    cout << '|';
                for (int j = 1; j <= s; j++)
                    cout << ' ';
                if (c == '2')
                    cout << ' ';
                else
                    cout << '|';
                if (k != n.length() - 1)
                    cout << ' ';
            }
            cout << "\n";
        }
        for (int k = 0; k < n.length(); k++)
        {
            char c = n[k];
            cout << ' ';
            for (int i = 1; i <= s; i++)
                if (c != '1' && c != '4' && c != '7')
                    cout << '-';
                else
                    cout << ' ';
            cout << ' ';
            if (k != n.length() - 1)
                cout << ' ';
        }
        cout << "\n\n";
    }

    return 0;
}