#include <bits/stdc++.h>

using namespace std;

bool is_prime[1001];
vector<int> prime;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j <= 1000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    const int sz = prime.size();
    int Case = 1;
    int s, t;
    while (cin >> s >> t && s + t)
    {
        vector<bool> visited(1001, false);
        queue<pair<int, int>> bfs;
        bfs.push({s, 0});
        bool found = false;
        while (!bfs.empty())
        {
            int now = bfs.front().first;
            int step = bfs.front().second;
            visited[now] = true;
            bfs.pop();
            if (now == t)
            {
                found = true;
                cout << "Case " << Case++ << ": " << step << "\n";
                break;
            }
            for (int i = 0; i < sz; i++)
            {
                if (prime[i] >= now) break;
                if (now + prime[i] > t) break;
                if (now % prime[i] != 0) continue;
                int tmp = now + prime[i];
                if (tmp <= t && !visited[tmp])
                {
                    bfs.push({tmp, step + 1});
                }
            }
        }
        if (!found)
            cout << "Case " << Case++ << ": -1\n";
    }

    return 0;
}