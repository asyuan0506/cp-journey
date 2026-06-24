#include <bits/stdc++.h>

using namespace std;

struct proposal
{
    string brand;
    double compliance;
    float price;
};

bool cmp(proposal a, proposal b)
{
    if (a.compliance > b.compliance)
        return true;
    if (a.compliance == b.compliance)
        return a.price < b.price;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    int cnt = 0;
    bool first = true;
    while (cin >> n >> p)
    {
        if (n == 0 && p == 0)
            break;
        if (!first)
            cout << "\n";
        first = false;
        cin >> ws;
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
        }
        vector<proposal> pro(p);
        for (int i = 0; i < p; i++)
        {
            int met_requirements;
            getline(cin, pro[i].brand);
            cin >> pro[i].price >> met_requirements;
            cin >> ws;
            for (int j = 0; j < met_requirements; j++)
            {
                string tmp;
                getline(cin, tmp);
            }
            pro[i].compliance = (double)met_requirements / (double)n;
        }
        stable_sort(pro.begin(), pro.end(), cmp);
        cout << "RFP #" << ++cnt << "\n"
             << pro[0].brand << "\n";
    }

    return 0;
}