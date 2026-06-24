#include <bits/stdc++.h>

using namespace std;

int Find(int a, vector<int> &v)
{
    // while (v[a] != -1)
    //     a = v[a];
    // return a;
    if (v[a] == -1) return a;
    else
    {
        v[a] = Find(v[a], v);
        return v[a];
    }
}

void Union(int a, int b, vector<int> &v)
{
    int p1 = Find(a, v);
    int p2 = Find(b, v);
    if (p1 != p2)
        v[p2] = p1;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> v(N + 1, -1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b, v);
    }
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a, v) == Find(b, v))
            cout << ":)\n";
        else
            cout << ":(\n";
    }

    return 0;
}