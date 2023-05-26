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
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node *insertattail(Node *&anshead, Node *&anstail, int digit)
{
    if (anshead == NULL)
    {
        Node *temp = new Node(digit);
        anshead = temp;
        anstail = temp;
    }
    else
    {
        Node *temp = new Node(digit);
        anstail->next = temp;
        anstail = temp;
    }
}
Node *add(Node *&first, Node *&second)
{

    int carry = 0;
    Node *anshead = NULL;
    Node *anstail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insertattail(anshead, anstail, digit);
        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return anshead;
}
Node *addtwolist(Node *&first , Node *&second)
{
    first = reverse(first);
    second = reverse(second);

    Node *ans = add(first, second);

    ans = reverse(ans);
    return ans;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head1 = node1;
    insertathead(head1, 4);
    cout << "First Linked List->" << endl;
    print(head1);
    Node *node2 = new Node(5);
    Node *head2 = node2;
    insertathead(head2, 4);
    insertathead(head2, 3);
    cout << "second linked list->" << endl;
    print(head2);
    Node *lol = addtwolist(head1, head2);
    cout << "After adding two list." << endl;
    print(lol);
    
    return 0;
}