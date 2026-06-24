#include <bits/stdc++.h>
const double PI = acos(-1.0);

using namespace std;

int main()
{
    double D, V;
    while (cin >> D >> V)
    {
        if (D == 0.0 && V == 0.0)
            break;
        double r = D / 2.0;
        double rest = D * r * r * PI - V;
        double ans = pow(6.0 * (rest / PI - (D * D * D / 12.0)), 1.0/3.0);
        cout << setprecision(3) << fixed << ans << "\n";
    }

    return 0;
}