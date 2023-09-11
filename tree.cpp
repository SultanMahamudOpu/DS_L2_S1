#include <bits/stdc++.h>
using namespace std;

class tree_node
{
public:
    int data;
    tree_node *left_child;
    tree_node *right_child;

    tree_node(int val)
    {
        data = val;
        left_child = NULL;
        right_child = NULL;
    }
};

void in_order(tree_node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left_child);
    cout << root->data << " ";
    in_order(root->right_child);
}

void pre_order(tree_node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left_child);
    pre_order(root->right_child);
}

void post_order(tree_node *root)
{
    if (root == NULL)
    {
        return;
    }

    post_order(root->left_child);
    post_order(root->right_child);
    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;

    tree_node *all_nodes[n];

    for (int i = 0; i < n; i++)
    {
        all_nodes[i] = new tree_node(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int value, left, right;
        cin >> value >> left >> right;

        all_nodes[i]->data = value;

        if (left != -1)
        {
            all_nodes[i]->left_child = all_nodes[left];
        }

        if (right != -1)
        {
            all_nodes[i]->right_child = all_nodes[right];
        }
    }

    in_order(all_nodes[0]);
    cout << endl;
    pre_order(all_nodes[0]);
    cout << endl;
    post_order(all_nodes[0]);

    // cout << st << endl;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/