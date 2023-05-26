#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertathead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *middle(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *&left, Node *&right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;

    return ans;
}
Node *mergesort(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = middle(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);

    Node *result = merge(left, right);

    return result;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    insertathead(head, 3);
    insertathead(head, 9);
    insertathead(head, 1);
    insertathead(head, 8);
    insertathead(head, 6);
    cout << "Before sort linked list->" << endl;
    print(head);
    cout << "After sort linke list->" << endl;
    Node *fuck = mergesort(head);
    print(fuck);

    return 0;
}