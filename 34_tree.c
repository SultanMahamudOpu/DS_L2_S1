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
    tree *new_node = (tree *)malloc(sizeof(tree));
    new_node->data = val;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
}

void in_order(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order(root->left_child);
    printf("%d ", root->data);
    in_order(root->right_child);
}

void pre_order(tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    pre_order(root->left_child);
    pre_order(root->right_child);
}

void post_order(tree *root)
{
    if (root == NULL)
    {
        return;
    }

    post_order(root->left_child);
    post_order(root->right_child);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    tree *all_nodes[n];

    for (int i = 0; i < n; i++)
    {
        all_nodes[i] = set_tree(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int val, left, right;
        scanf("%d%d%d", &val, &left, &right);

        all_nodes[i]->data = val;

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
    printf("\n");
    pre_order(all_nodes[0]);
    printf("\n");
    post_order(all_nodes[0]);
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