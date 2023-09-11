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

tree_node *insertion_BST(tree_node *root, int val)
{
    tree_node *new_node = new tree_node(val);

    if (root == NULL)
    {
        root = new_node;
        return root;
    }

    if (val < root->data)
    {
        root->left_child = insertion_BST(root->left_child, val);
    }
    else if (val > root->data)
    {
        root->right_child = insertion_BST(root->right_child, val);
    }

    return root;
}

int main()
{
    int n;
    cin >> n;

    tree_node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insertion_BST(root, val);
    }

    in_order(root);
}