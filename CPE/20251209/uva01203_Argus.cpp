#include <bits/stdc++.h>

using namespace std;

struct q {
    int nxt;
    int qnum;
    int period;
};

struct cmp{
    bool operator() (q a, q b)
    {
        if (a.nxt == b.nxt)
            return a.qnum > b.qnum;
        return a.nxt > b.nxt;
    }
};

int main()
{
    string s;
    priority_queue<q, vector<q>, cmp> pq;
    while (cin >> s && s != "#")
    {
        int qnum, p;
        cin >> qnum >> p;
        q tmp;
        tmp.nxt = p;
        tmp.period = p;
        tmp.qnum = qnum;
        pq.push(tmp);
    }
    int k;
    cin >> k;
    while (k--)
    {
        q tmp = pq.top();
        pq.pop();
        cout << tmp.qnum << "\n";
        tmp.nxt += tmp.period;
        pq.push(tmp);
    }

    return 0;
}