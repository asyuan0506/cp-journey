#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime;
const int maxN = 1000000;

void init()
{
    is_prime.assign(maxN, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < maxN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j < maxN; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    init();
    int num;
    while (cin >> num && num != 0)
    {
        bool found = false;
        for (int i = 1; i < num; i++)
        {
            if (is_prime[i] && is_prime[num - i])
            {
                found = true;
                cout << num << " = " << i << " + " << num - i << "\n";
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}