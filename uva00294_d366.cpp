/*
    d366.cpp
    UVa 294 - Divisors
    Created by Juan Miguel Jimenez Fuentes on 21/11/20.

    Build a prime table first
    And use this formula: N=A1^B1 * A2^B2 -> divisors = (B1 + 1) * (B2 + 1) (e.g 6 = 2^1 * 3^1 -> (1 + 1) * (1 + 1) = 4)
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool not_prime[32000]; // Default all 0, sqrt 1e9 = 31622.8
vector<int> prime;     // Build a prime table

int main()
{
    for (int i = 2; i < 32000; i++)
    {
        if (!not_prime[i])
        { // if i is a prime
            prime.push_back(i);
            for (int j = i + i; j < 32000; j += i)
            { // Set i's multiple numbers to not prime
                not_prime[j] = true;
            }
        }
    }
    int N;
    cin >> N;
    while (N--)
    {
        int L, U;
        cin >> L >> U;
        cout << "Between " << L << " and " << U << ", ";

        int P;
        int D = -1;
        for (int i = L; i <= U; i++)
        {
            // N=A1^B1 * A2^B2 -> divisors = (B1 + 1) * (B2 + 1)
            int divisors = 1;
            int tmp = i;
            for (int j : prime)
            {

                if (tmp % j == 0)
                {
                    int power = 1; // plus 1
                    while (tmp > 1 && tmp % j == 0)
                    {
                        power++;
                        tmp /= j;
                    }
                    divisors *= power;
                }
                if (tmp == 1 || j > sqrt(i))
                    break;
            }

            if (divisors > D)
            {
                P = i;
                D = divisors;
            }
        }

        cout << P << " has a maximum of " << D << " divisors." << endl;
    }

    return 0;
}