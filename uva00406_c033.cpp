#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int main()
{
    vector<bool> is_prime(1001, true); // 0 un used
    is_prime[1] = true;
    for (int i = 2; i <= 32; i++) // sqrt(1000) = 31.62
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= 1000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    vector<vector<int>> prime_to_N(1001);
    prime_to_N[1].push_back(1);
    for (int i = 2; i <= 1000; i++)
    {
        prime_to_N[i] = prime_to_N[i - 1];
        if (is_prime[i])
            prime_to_N[i].push_back(i);
    }

    int N, C;
    while (cin >> N >> C)
    {
        cout << N << " " << C << ":";
        int number_of_prime = prime_to_N[N].size();
        if (number_of_prime % 2 == 0)
        {
            if (2 * C >= number_of_prime)
            {
                for (int prime : prime_to_N[N])
                {
                    cout << " " << prime;
                }
            }
            else
            {
                int idx = number_of_prime / 2 - C;
                for (int j = 0; j < (2 * C); j++)
                {
                    cout << " " << prime_to_N[N][idx + j];
                }
            }
        }
        else
        {
            if (2 * C - 1 >= number_of_prime)
            {
                for (int prime : prime_to_N[N])
                {
                    cout << " " << prime;
                }
            }
            else
            {
                int idx = number_of_prime / 2 - C + 1;
                for (int j = 0; j < (2 * C) - 1; j++)
                {
                    cout << " " << prime_to_N[N][idx + j];
                }
            }
        }
        cout << endl
             << endl;
    }

    return 0;
}*/

int main()
{
    bool is_prime[1001] = {true};
    for (int i = 0; i < 1001; i++)
        is_prime[i] = true;
    vector<int> prime_table(1, 1);
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime[i])
        {
            prime_table.push_back(i);
            for (int j = 2 * i; j <= 1000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    int N, C;
    while (cin >> N >> C)
    {
        cout << N << " " << C << ":";
        auto it = upper_bound(prime_table.begin(), prime_table.end(), N); // Find the samllest prime that > N
        int K = it - prime_table.begin();

        for (int i = max(0, K / 2 - C + (K % 2)); i < min(K, K / 2 + C); i++)
        {
            cout << " " << prime_table[i];
        }
        cout << endl;
    }

    return 0;
}