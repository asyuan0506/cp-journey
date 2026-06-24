/*
    c113.cpp
    Intersecting Lines
    UVA - 378
    Better case classification: https://yuihuang.com/zj-c113/
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << "INTERSECTING LINES OUTPUT" << endl;

    while (N--)
    {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double m1 = (y2 - y1) / (x2 - x1), m2 = (y4 - y3) / (x4 - x3);
        double b1 = y1 - m1 * x1, b2 = y3 - m2 * x3;
        if (abs(m1) == abs(m2))
        {
            if (b1 == b2)
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
        }
        else
        {
            cout << "POINT ";
            // 0 = (m1 - m2)x + (b1 - b2) -> x = (b2 - b1) / (m1 - m2)
            double inter_x = (b2 - b1) / (m1 - m2);
            double inter_y = m1 * inter_x + b1;
            if (abs(m1) >= 1e+300)
            {
                inter_x = x1;
                inter_y = m2 * inter_x + b2;
            }
            else if (abs(m2) >= 1e+300)
            {
                inter_x = x2;
                inter_y = m1 * inter_x + b1;
            }
            cout << setprecision(2) << fixed;
            cout << inter_x << " " << inter_y << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}