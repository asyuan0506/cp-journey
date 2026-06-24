#include <iostream>
#include <string>

using namespace std;

struct my_tree
{
    my_tree(char ch) : c(ch), left(nullptr), right(nullptr) {}
    char c;
    my_tree *left;
    my_tree *right;
};

my_tree *build_tree(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return nullptr;
    my_tree *root = new my_tree(s1[0]);
    int root_pos = s2.find(s1[0]);
    string left_nodes = s2.substr(0, root_pos);
    string right_nodes = s2.substr(root_pos + 1);
    string s1_left = "", s1_right = "";
    for (char c1 : s1)
    {
        for (char c2 : left_nodes)
        {
            if (c2 == c1)
                s1_left += c1;
        }
        for (char c2 : right_nodes)
        {
            if (c2 == c1)
                s1_right += c1;
        }
    }
    root->left = build_tree(s1_left, left_nodes);
    root->right = build_tree(s1_right, right_nodes);

    return root;
}

void show_post(my_tree *node)
{
    if (node == nullptr)
        return;
    show_post(node->left);
    show_post(node->right);
    cout << node->c;
}

void clean(my_tree *node)
{
    if (node == nullptr)
    {
        return;
    }
    clean(node->left);
    clean(node->right);
    delete node;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        my_tree *root = build_tree(s1, s2);
        show_post(root);
        cout << endl;
        clean(root);
    }

    return 0;
}