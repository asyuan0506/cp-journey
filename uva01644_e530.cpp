#include <bits/stdc++.h>

using namespace std;

const int maxn = 1299710;
bool not_prime[maxn];

int main()
{
    not_prime[0] = true;
    not_prime[1] = true;
    vector<int> prime;
    for (int i = 2; i < maxn; i++)
    {
        if (!not_prime[i])
        {
            prime.push_back(i);
            for (int j = i + i; j < maxn; j += i)
            {
                not_prime[j] = true;
            }
        }
    }

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int>::iterator iter = lower_bound(prime.begin(), prime.end(), n);
        if (n == *iter)
        {
            cout << "0\n";
        }
        else
        {
            cout << *iter - *(iter - 1) << "\n";
        }
    }

    return 0;
}