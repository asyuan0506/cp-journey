#include <bits/stdc++.h>

using namespace std;

bool possible(int coin, bool heavier, vector<vector<vector<int>>> &weights)
{
    for (int i = 0; i < weights.size(); i++)
    {
        int op = weights[i][2][0];
        int left = 0, right = 0;
        for (int c : weights[i][0])
        {
            if (c == coin)
                left = heavier? 1 : -1;
        }
        for (int c : weights[i][1])
        {
            if (c == coin)
                right = heavier? 1 : -1;
        }
        if (op == 0 && left != right) // Same
        {
            return false;
        }
        if (op == 1 && left <= right)
        {
            return false;
        }
        if (op == 2 && left >= right)
            return false;
    }
    return true;
}

int main()
{   
    int T;
    cin >> T;
    bool first = true;
    while (T--)
    {
        if (!first) cout << "\n";
        first = false;
        int n, k;
        cin >> n >> k;
        vector<vector<vector<int>>> weights(k, vector<vector<int>> (3)); // [i][0]: left, [i][1]: right, [i][2]: operator
        for (int i = 0; i < k; i++)
        {
            int c;
            cin >> c;
            vector<int> left(c), right(c);
            for (int i = 0; i < c; i++)
                cin >> left[i];
            for (int i = 0; i < c; i++)
                cin >> right[i];
            char op;
            cin >> op;
            int op_int;
            if (op == '=') op_int = 0;
            else if (op == '>') op_int = 1;
            else if (op == '<') op_int = 2;
            weights[i][0] = left;
            weights[i][1] = right;
            weights[i][2].push_back(op_int);
        }
        int possibles = 0;
        int false_coin = -1;
        for (int i = 1; i <= n; i++)
        {   // 0: assume coin i lighter, 1: assume coin i heavier
            if (possible(i, 0, weights) || possible(i, 1, weights))
            {
                possibles++;
                false_coin = i;
            }
        }
        if (possibles != 1) cout << "0\n";
        else cout << false_coin << "\n";
    }
    return 0;
}