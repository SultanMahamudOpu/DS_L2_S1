#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node tree;
struct tree_node
{
    int data;
    tree *left_child;
    tree *right_child;
};

void *set_tree(int val)
{
    tree *new_tree = (tree *)malloc(sizeof(tree));
    new_tree->data = val;
    new_tree->left_child = NULL;
    new_tree->right_child = NULL;
}

tree *insertion_BST(tree *root, int val)
{
    tree *new_node = set_tree(val);
    if (root == NULL)
    {
        root = new_node;
        return root;
    }
    if (val < root->data)
        root->left_child = insertion_BST(root->left_child, val);
    else if (val > root->data)
        root->right_child = insertion_BST(root->right_child, val);
    return root;
}

void in_order(tree *root)
{
    if (root == NULL)
        return;
    in_order(root->left_child);
    printf("%d ", root->data);
    in_order(root->right_child);
}

int main()
{
    int n;
    scanf("%d", &n);
    tree *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        root = insertion_BST(root, val);
    }
    in_order(root);
}