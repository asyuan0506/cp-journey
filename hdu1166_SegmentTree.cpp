#include <iostream>
#include <string>

using namespace std;

const int maxn = 50005;
int st[maxn << 2];

void pull(int x)
{
    st[x] = st[x << 1] + st[x << 1 | 1];
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        cin >> st[x];
        return;
    }
    int mid = (l + r) / 2;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    pull(x);
}

int query(int x, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return st[x];
    int mid = (l + r) / 2;
    int ret = 0;
    if (ql <= mid)
        ret += query(x << 1, l, mid, ql, qr);
    if (qr > mid)
        ret += query(x << 1 | 1, mid + 1, r, ql, qr);
    return ret;
}

void update(int x, int l, int r, int pos, int val)
{
    if (l == r)
    {
        st[x] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(x << 1, l, mid, pos, val);
    else
        update(x << 1 | 1, mid + 1, r, pos, val);
    pull(x);
}

int main()
{
    int t;
    cin >> t;
    int Case = 0;
    while (t--)
    {
        cout << "Case " << ++Case << ":\n";
        int n;
        cin >> n;
        build(1, 1, n);
        string op;
        while (cin >> op && op != "End")
        {
            int a, b;
            cin >> a >> b;
            if (op == "Add")
                update(1, 1, n, a, b);
            else if (op == "Sub")
                update(1, 1, n, a, -b);
            else if (op == "Query")
                cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}