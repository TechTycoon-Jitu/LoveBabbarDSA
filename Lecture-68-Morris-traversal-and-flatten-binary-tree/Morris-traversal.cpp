#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newnode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
void morristraversalinorder(struct Node *root)
{
    struct Node *current, *pre;
    if (root == NULL)
    {
        return;
    }
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
int main()
{
    struct Node *root = newnode(1);
    root->left = newnode(2);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right = newnode(3);

    morristraversalinorder(root);

    return 0;
}