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
void Inserthead(Node *&head, int data)
{
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
Node *kreverse(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if (next != NULL)
    {
        head->next = kreverse(next, k);
    }
    return prev;
}
int main()
{
    Node *node1 = new Node(8);
    Node *head = node1;
    Inserthead(head, 3);
    Inserthead(head, 7);
    Inserthead(head, 5);
    print(head);
    head = kreverse(head, 2);
    print(head);

    return 0;
}