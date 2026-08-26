#include <bits/stdc++.h>

using namespace std;

struct weighting 
{
    vector<int> left;
    vector<int> right;
    char op;
};

bool possible(int coin, bool heavier, vector<weighting> &weights)
{
    for (int i = 0; i < weights.size(); i++)
    {
        int left = 0, right = 0;
        for (int c : weights[i].left)
            if (coin == c)
                left = heavier? 1 : -1;
        for (int c : weights[i].right)
            if (coin == c)
                right = heavier? 1 : -1;
        if (weights[i].op == '=' && left != right) 
            return false;
        else if (weights[i].op == '>' && left <= right)
            return false;
        else if (weights[i].op == '<' && left >= right)
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

        vector<weighting> weights(k);
        
        for (int i = 0; i < k; i++)
        {
            int c;
            cin >> c;
            vector<int> left(c), right(c);
            for (int i = 0; i < c; i++)
                cin >> left[i];
            for (int i = 0; i < c; i++)
                cin >> right[i];
            
            weights[i].left = left;
            weights[i].right = right;
            cin >> weights[i].op;
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