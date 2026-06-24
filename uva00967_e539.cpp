#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool is_prime[1000000];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    vector<int> prime;
    for (int i = 2; i < 1000000; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j < 1000000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    vector<int> circular;
    for (auto i = lower_bound(prime.begin(), prime.end(), 100); i < prime.end(); i++)
    {
        int prime_num = *i;
        int cnt = 2; // *i is prime so no need to check
        int denominator = 100;
        while (prime_num / denominator >= 10)
        {
            cnt++;
            denominator *= 10;
        }
        for (cnt; cnt > 0; cnt--)
        {
            // int least = prime_num / denominator;
            // prime_num = (prime_num % denominator) * 10 + least;
            prime_num = prime_num % denominator * 10 + prime_num / denominator;
            if (!is_prime[prime_num])
            {
                break;
            }
        }
        if (cnt == 0)
        {
            circular.push_back(*i);
        }
    }

    int a, b;
    while (cin >> a)
    {
        if (a == -1)
            break;
        cin >> b;
        int cnt = 0;
        for (auto i = lower_bound(circular.begin(), circular.end(), a); i < upper_bound(circular.begin(), circular.end(), b); i++)
        {
            cnt++;
        }
        if (cnt == 0)
        {
            cout << "No Circular Primes.\n";
        }
        else if (cnt == 1)
        {
            cout << "1 Circular Prime.\n";
        }
        else
        {
            cout << cnt << " Circular Primes.\n";
        }
    }

    return 0;
}