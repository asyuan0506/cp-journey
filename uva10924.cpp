#include <bits/stdc++.h>

using namespace std;

const int maxn = 1050; // 52 * 20 = 1040
bool is_prime[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = false;
    for (int i = 2; i < maxn; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j < maxn; j += i)
                is_prime[j] = false;
        }
    }
    string word;
    while (cin >> word)
    {
        int sum = 0;
        for (char c : word)
        {
            if ('a' <= c && c <= 'z')
                sum += c - 'a' + 1;
            else if ('A' <= c && c <= 'Z')
                sum += c - 'A' + 27;
        }
        if (is_prime[sum])
            cout << "It is a prime word.\n";
        else
            cout << "It is not a prime word.\n";
    }

    return 0;
}