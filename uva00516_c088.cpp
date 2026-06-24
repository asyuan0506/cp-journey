#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

// int main()
// {
//     vector<bool> is_prime(32768, true);
//     for (int i = 2; i < 32768; i++)
//     {
//         if (is_prime[i])
//         {
//             for (int j = 2 * i; j < 32678; j += i)
//             {
//                 is_prime[j] = false;
//             }
//         }
//     }

//     string line;
//     stringstream ss;
//     while (getline(cin, line))
//     {
//         if (line == "0")
//             break;

//         ss.clear();
//         ss.str(line);
//         int tmp, pwr;
//         int X = 1;
//         while (ss >> tmp >> pwr)
//         {
//             X *= (int)pow(tmp, pwr);
//         }

//         vector<pair<int, int>> ans;
//         X--;
//         for (int i = 2; i < 32768 && X != 1; i++) // Can be optimized by sqrt(X)
//         {
//             if (!is_prime[i])
//                 continue;
//             int pwr = 1;
//             for (pwr; pwr <= 15; pwr++)
//             {
//                 if (X % (int)pow(i, pwr) != 0)
//                     break;
//             }
//             pwr--;
//             if (pwr > 0)
//             {
//                 ans.push_back(make_pair(i, pwr));
//                 X /= pow(i, pwr);
//             }
//         }
//         for (int i = ans.size() - 1; i >= 0; i--)
//             cout << ans[i].first << " " << ans[i].second << " ";
//         cout << endl;
//     }

//     return 0;
// }

string Factorization(int num)
{
    int b = 2;
    string s = "";
    vector<pair<int, int>> ans;
    while (num != 1)
    {
        int p = 0;
        while (num % b == 0)
        {
            p++;
            num /= b;
        }
        if (p > 0)
        {
            ans.push_back(make_pair(b, p));
        }
        b++;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        s += to_string(ans[i].first) + " " + to_string(ans[i].second) + " ";
    }
    return s;
}

int main()
{
    string line;
    stringstream ss;
    while (getline(cin, line))
    {
        if (line == "0")
            break;

        ss.clear();
        ss.str(line);

        int tmp, pwr;
        int X = 1;
        while (ss >> tmp >> pwr)
        {
            X *= pow(tmp, pwr);
        }
        X--;
        cout << Factorization(X) << endl;
    }

    return 0;
}