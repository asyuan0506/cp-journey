#include <iostream>
#include <map>
using namespace std;

int main()
{
    int Case = 0;
    int N;
    cin >> N;
    while (N--)
    {
        int num;
        map<int, bool> visited;
        cin >> num;
        bool happy = false;
        cout << "Case #" << ++Case << ": " << num << " ";
        int s_now = 0, s_last = num;
        while (s_last > 0 && visited.find(s_last) == visited.end())
        {
            visited[s_last] = true;
            while (s_last > 0)
            {
                int digit = s_last % 10;
                s_now += digit * digit;
                s_last /= 10;
            }
            if (s_now == 1)
            {
                cout << "is a Happy number.\n";
                happy = true;
                break;
            }
            s_last = s_now;
            s_now = 0;
        }
        if (!happy)
            cout << "is an Unhappy number.\n";
    }

    return 0;
}