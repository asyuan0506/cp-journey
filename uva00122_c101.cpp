#include <bits/stdc++.h>

using namespace std;

struct node
{
    int num;
    string r;
    node() : num(0), r("") {};
};

struct tree
{
    node* cur;
    tree* left;
    tree* right;
    tree() : cur(nullptr), left(nullptr), right(nullptr) {}; 
};

bool cmp (node a, node b)
{
    if (a.r.length() < b.r.length())
        return true;
    return a.r < b.r;
}

void clean(tree *t)
{
    queue<tree*> q;
    q.push(t);
    while (!q.empty())
    {
        tree* tmp = q.front();
        q.pop();
        if (tmp->left != nullptr) q.push(tmp->left);
        if (tmp->right != nullptr) q.push(tmp->right);
        delete tmp;
        tmp = nullptr;
    }
}

void bfs(tree* t)
{
    queue<tree*> q;
    q.push(t);
    bool first = true;
    while (!q.empty())
    {
        if (!first)
            cout << " ";
        first = false;
        tree* tmp = q.front();
        q.pop();
        cout << tmp->cur->num;
        if (tmp->left != nullptr) q.push(tmp->left);
        if (tmp->right != nullptr) q.push(tmp->right);
    }
    cout << "\n";
}

int main()
{
    vector<node> nodes;
    string s;
    while (cin >> s)
    {
        if (s == "()")
        {
            bool complete = true;
            tree *root = new tree;
            sort(nodes.begin(), nodes.end(), cmp); // sort for top-down
            for (int i = 0; i < nodes.size(); i++)
            {
                tree* now = root;
                for (char c : nodes[i].r)
                {
                    if (now->cur == nullptr) // sorted, so there is no null node on path
                    {
                        complete = false;
                        break;
                    }
                    if (c == 'L')
                    {
                        if (now->left == nullptr)
                        {
                            now->left = new tree();
                        }
                        now = now->left;
                    }
                    else if (c == 'R')
                    {
                        if (now->right == nullptr)
                        {
                            now->right = new tree;
                        }
                        now = now->right;
                    }
                }
                if (!complete) break;
                if (now->cur != nullptr) // duplicate node
                {
                    complete = false;
                    break;
                }
                now->cur = &nodes[i];
            }
            if (!complete)
                cout << "not complete\n";
            else
                bfs(root);
            nodes.clear();
            clean(root);
            continue;
        }
        node tmp;
        for (char c : s)
        {
            if ('0' <= c && c <= '9')
                tmp.num = tmp.num * 10 + (c - '0');
            else if (c == 'L' || c == 'R')
                tmp.r += c;
        }
        nodes.push_back(tmp);
    }

    return 0;
}