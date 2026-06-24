#include <bits/stdc++.h>

using namespace std;

int main()
{
    int students;
    while (cin >> students)
    {
        if (students == 0)
            break;
        vector<long long> cost(students, 0);
        long long total = 0;
        for (int i = 0; i < students; i++)
        {
            string s;
            cin >> s;
            long long cost_tmp = 0; // avoid floating point
            long long multiplier = 1;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == '.')
                    continue;
                cost_tmp += (s[j] - '0') * multiplier;
                multiplier *= 10;
            }
            cost[i] = cost_tmp;
            total += cost_tmp;
        }
        long long avg = total / students;
        long long remainder = total % students;
        long long exchange = 0;
        for (int i = 0; i < students; i++)
        {
            if (cost[i] > avg)
                remainder--;
            else
                exchange += avg - cost[i];
        }
        if (remainder > 0)
            exchange += remainder;
        cout << "$";
        long long left = exchange / 100;
        long long right = exchange % 100;
        cout << left << ".";
        if (right < 10)
            cout << 0;
        cout << right << "\n";
    }

    return 0;
}