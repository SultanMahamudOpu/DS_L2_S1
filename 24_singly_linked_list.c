#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list node;
struct list
{
    int data;
    node *next;
};
node *creat_new_node(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
}
node *insertion_at_head(node *head, int val)
{
    node *new_node = creat_new_node(val);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    new_node->next = head;
    head = new_node;
    return head;
}

node *insertion_at_tail(node *head, int val)
{
    node *new_node = creat_new_node(val);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return head;
}
node *deletion_at_head(node *head)
{
    if (head == NULL)
    {
        printf("Underflow!!!\n");
        return head;
    }
    head = head->next;
    return head;
}

node *deletion_at_tail(node *head)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return head;
    }
    node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        head = insertion_at_tail(head, a);
    }
    display(head);
}