#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        vector<int> seq(N);
        int tmp;
        while (cin >> tmp)
        {
            if (tmp == 0)
                break;

            seq[0] = tmp;
            for (int i = 1; i < N; i++)
            {
                cin >> seq[i];
            }

            vector<int> output_car(N);
            stack<int> car_stack;
            int idx = 0;
            for (int car = 1; car <= N; car++)
            {
                if (car == seq[idx])
                {
                    output_car[idx] = car;
                    idx++;
                }
                else
                {
                    if (!car_stack.empty() && car_stack.top() == seq[idx])
                    {
                        output_car[idx] = car_stack.top();
                        idx++;
                        car_stack.pop();
                        car--;
                    }
                    else
                    {
                        car_stack.push(car);
                    }
                }
            }
            while (!car_stack.empty())
            {
                output_car[idx] = car_stack.top();
                idx++;
                car_stack.pop();
            }

            bool yes = true;
            for (int i = 0; i < N; i++)
            {
                if (output_car[i] != seq[i])
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
                }
    }

    return 0;
}*/

int main()
{
    int N;
    while (cin >> N)
    {
        if (N == 0)
            break;
        vector<int> seq(N);
        int tmp;
        while (cin >> tmp)
        {
            if (tmp == 0)
                break;

            seq[0] = tmp;
            for (int i = 1; i < N; i++)
            {
                cin >> seq[i];
            }

            stack<int> station;
            int i = 0;
            int point = 1;
            for (i; i < N; i++)
            {
                if (!station.empty() && station.top() == seq[i])
                {
                    station.pop();
                }
                else if (seq[i] >= point)
                {
                    for (int j = point; j < seq[i]; j++)
                        station.push(j);
                    point = seq[i] + 1;
                }
                else
                    break;
            }
            if (i == N)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}