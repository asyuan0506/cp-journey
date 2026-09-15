#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    cnt++;
                }
            }
        }
        cout << "Minimum exchange operations : " << cnt << "\n";
    }

    return 0;
}