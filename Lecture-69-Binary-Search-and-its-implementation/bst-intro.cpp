#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void preordertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->data << " ";
}
void inordetraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inordetraversal(root->left);
    cout << root->data << " ";
    inordetraversal(root->right);
}
Node *InsertInToBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Insert right part
    if (data > root->data)
    {
        root->right = InsertInToBST(root->right, data);
    }
    // insert left part
    else
    {
        root->left = InsertInToBST(root->left, data);
    }
    return root;
}
void takeinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertInToBST(root, data);
        cin >> data;
    }
}
Node *minval(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxval(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node *inordersuccesor(Node *root, int val)
{
    Node *succesor = NULL;
    while (root != NULL)
    {
        if (val >= root->data)
        {
            root = root->right;
        }
        else
        {
            succesor = root;
            root = root->left;
        }
    }
    return succesor;
}
Node *deltefromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // rigth child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deltefromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left parte me jao
        root->left = deltefromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deltefromBST(root->right, val);
        return root;
    }
}

Node *inorderpredecessor(Node *root, int val)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (val >= root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
            predecessor = root;
        }
    }
    return predecessor;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data to create BST ->" << endl;
    takeinput(root);
    cout << endl
         << "Levelorder Traversal->" << endl;
    levelOrderTraversal(root);
    cout << endl
         << "Preorder Traversal is->" << endl;
    preordertraversal(root);
    cout << endl
         << "Postorder Traversal is->" << endl;
    postordertraversal(root);
    cout << endl
         << "Inorder Traversal is ->" << endl;
    inordetraversal(root);

    cout << endl
         << "Minmimum value of this BST tree is ->" << minval(root)->data << endl;

    cout << endl
         << "Maxmum value of this BST tree is ->" << maxval(root)->data << endl;
    cout << "Succesor is ->" << inordersuccesor(root, 30)->data << endl;
    cout << "Predessor is ->" << inorderpredecessor(root, 30)->data << endl;
    //Deltion
    root = deltefromBST(root,90);
    cout << endl
         << "Levelorder Traversal->" << endl;
    levelOrderTraversal(root);
    cout << endl
         << "Preorder Traversal is->" << endl;
    preordertraversal(root);
    cout << endl
         << "Postorder Traversal is->" << endl;
    postordertraversal(root);
    cout << endl
         << "Inorder Traversal is ->" << endl;
    inordetraversal(root);

    cout << endl
         << "Minmimum value of this BST tree is ->" << minval(root)->data << endl;

    cout << endl
         << "Maxmum value of this BST tree is ->" << maxval(root)->data << endl;
    cout << "Succesor is ->" << inordersuccesor(root, 30)->data << endl;
    cout << "Predessor is ->" << inorderpredecessor(root, 30)->data << endl;

    return 0;
}