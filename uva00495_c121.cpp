#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string my_sum(string s1, string s2)
{
    int l1 = s1.size(), l2 = s2.size();
    string result = "";
    bool carry = false;
    for (int i = 0; i < l2; i++)
    {
        if (i >= l1)
        {
            s1 += '0';
        }

        char tmp = carry + s1[i] - '0' + s2[i];
        carry = tmp > '9';
        if (carry)
        {
            tmp -= 10;
        }
        result += tmp;
    }
    if (carry)
        result += '1';
    return result;
}

int main()
{
    vector<string> fib(5001, "0");
    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i <= 5000; i++)
    {
        fib[i] = my_sum(fib[i - 2], fib[i - 1]);
    }
    int n;
    while (cin >> n)
    {
        string ans_rev = fib[n];
        reverse(ans_rev.begin(), ans_rev.end());
        cout << "The Fibonacci number for " << n << " is " << ans_rev << endl;
    }

    return 0;
}