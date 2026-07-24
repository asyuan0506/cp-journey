#include <bits/stdc++.h>

using namespace std;

// Segment Tree
// vector<int> v;
// vector<int> seg;

// void Build(int p, int l, int r)
// {
//     if (l >= r)
//     {
//         seg[p] = v[l];
//         return;
//     }
//     int mid = (l + r) >> 1;
//     Build(p << 1, l, mid);
//     Build(p << 1 | 1, mid + 1, r);
//     seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
// }

// int Query(int p, int l, int r, int L, int R)
// {
//     if (L <= l && R >= r)
//         return seg[p];

//     int mid = (l + r) >> 1;
//     int res = INT_MIN;
//     if (L <= mid)
//         res = max(res, Query(p << 1, l, mid, L, R));
//     if (R > mid)
//         res = max(res, Query(p << 1 | 1, mid + 1, r, L, R));
//     return res;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N;
//     v.resize(N);
//     seg.resize(4 * N);
//     for (int i = 0; i < N; i++)
//         cin >> v[i];
//     Build(1, 0, N - 1);

//     cin >> M;
//     for (int i = 0; i < M; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a > b)
//             swap(a, b);
//         cout << Query(1, 0, N - 1, a - 1, b - 1) << "\n";
//     }

//     return 0;
// }

// Sparse Table
// vector<vector<int>> st;

// void Build(vector<int> &init)
// {
//     st.clear();
//     st.push_back(init);
//     const int N = init.size();

//     for (int k = 1; (1 << k) <= N; k++)
//     {
//         vector<int> tmp;
//         for (int j = 0; j + (1 << k) <= N; j++)
//             tmp.push_back(max(st[k - 1][j], st[k - 1][j + (1 << (k - 1))]));
//         st.push_back(tmp);
//     }
// }

// int Query(int L, int R)
// {
//     int len = R - L + 1;
//     // int k = 0;
//     // while (1 << (k + 1) <= len)
//     //     k++;
//     int k = floor(log2(len));
//     return max(st[k][L], st[k][R - (1 << k) + 1]);
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int N, M;
//     cin >> N;
//     vector<int> tmp(N);
//     for (int i = 0; i < N; i++)
//         cin >> tmp[i];
//     Build(tmp);

//     cin >> M;
//     for (int i = 0; i < M; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         if (a > b)
//             swap(a, b);
//         cout << Query(a - 1, b - 1) << "\n";
//     }

//     return 0;
// }

// Mo's Algorithm
struct query
{
    int left;
    int right;
    int id;
    query() {};
    query(int l, int r, int id) : left(l), right(r), id(id) {}
};

int block_size;
bool cmp(query& a, query& b)
{
    int block_a = a.left / block_size;
    int block_b = b.left / block_size;
    if (block_a == block_b)
        return a.right < b.right;
    
    return block_a < block_b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    block_size = int(sqrt(N));

    cin >> M;
    vector<query> queries(M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        queries[i] = query(--a, --b, i);
    }
    sort(queries.begin(), queries.end(), cmp);
    multiset<int> window;
    vector<int> ans(M);
    int cur_left = 0;
    int cur_right = -1;
    for (query q : queries)
    {
        while (cur_right < q.right)
        {
            window.insert(nums[++cur_right]);
        }
        while (cur_right > q.right)
        {
            auto it = window.find(nums[cur_right--]);
            window.erase(it);
        }
        while (cur_left > q.left)
        {
            window.insert(nums[--cur_left]);
        }
        while (cur_left < q.left)
        {
            auto it = window.find(nums[cur_left++]);
            window.erase(it);
        }
        ans[q.id] = *window.rbegin();
    }

    for (int i = 0; i < M; i++)
        cout << ans[i] << "\n";

    return 0;
}