#include <bits/stdc++.h>

using namespace std;

int main()
{
    double multiplier[3] = {sqrt(3.0) / 2, 2 * sqrt(3.0) - 3, sqrt(3.0) / 4};
    double s;
    while (cin >> s)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << setprecision(10) << fixed << s * multiplier[i] << " ";
        }
        double a = -5.0 / 3.0;
        double b = -7.0 * s / sqrt(3.0);
        double c = 7.0 * s * s / 4.0;
        cout << setprecision(10) << fixed << (-b - sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
        cout << "\n";
    }

    return 0;
}