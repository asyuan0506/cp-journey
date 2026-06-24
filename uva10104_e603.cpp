#include <bits/stdc++.h>

using namespace std;
#define ll long long

void ExEuclidean(ll A, ll B, ll &X, ll &Y, ll &D)
{
    if (B == 0)
    {
        D = A;
        X = 1;
        Y = 0;
    }
    else
    {
        ExEuclidean(B, A % B, Y, X, D);
        Y -= (A / B) * X;
    }

}

int main()
{
    ll A, B, X, Y, D;
    while (cin >> A >> B)
    {
        ExEuclidean(A, B, X, Y, D);
        cout << X << " " << Y << " " << D << "\n";
    }

    return 0;
}