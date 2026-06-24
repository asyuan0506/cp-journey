#include <bits/stdc++.h>

using namespace std;

bool BiColorAble(int node, vector<pair<int, vector<int>>> &nodes, bool color)
{
    if (nodes[node].first == color)
    {
        return true;
    }
    else if (nodes[node].first != -1 && nodes[node].first != color)
    {
        return false;
    }
    else if (nodes[node].first == -1)
    {
        nodes[node].first = color;
        for (auto i = nodes[node].second.begin(); i < nodes[node].second.end(); i++)
        {
            if (!BiColorAble(*i, nodes, !color))
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<pair<int, vector<int>>> nodes(n, make_pair(-1, vector<int>(0))); // first: node color second: connected edge
        // -1: not color yet, 0, 1: colors
        int l;
        cin >> l;
        for (int i = 0; i < l; i++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            nodes[node1].second.push_back(node2);
            nodes[node2].second.push_back(node1);
            /* 
            Although it's strongly connected, if we only record node1 to node2
            and if there is a only way from 1 to 0,
            it will be no edge from 0 to 1.
            */
        }
        bool bi_color = BiColorAble(0, nodes, 0);
        if (bi_color)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}