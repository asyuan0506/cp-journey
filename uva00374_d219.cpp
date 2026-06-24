/*
    d219.cpp
    00374 - Big Mod
    Prevent overflow  B^P % M = (B^(P/2) % M) * (B^(P/2) % M) (mod M)
    Faster quick power
    Can optimize by using bit operation and while loop
*/

#include <iostream>

using namespace std;

long long quick_power(long long base, long long power, long long moduler)
{
    if (power == 0)
        return 1;
    if (power == 1)
        return base % moduler;

    long long tmp = quick_power(base, power / 2, moduler);
    if (power % 2 == 1)
    {
        tmp = tmp * tmp * base % moduler;
    }
    else
        tmp = tmp * tmp % moduler;

    return tmp;
}

int main()
{
    long long B, P, M;
    while (cin >> B >> P >> M)
    {
        cout << quick_power(B, P, M) << endl;
    }

    return 0;
}