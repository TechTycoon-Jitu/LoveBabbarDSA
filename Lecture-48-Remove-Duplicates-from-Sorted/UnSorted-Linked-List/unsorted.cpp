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
Node *unsorted(Node *&head)
{
    if (head == NULL)
    {
          return NULL;
    }
    Node *curr = head;
    while (curr != NULL && curr->next!=NULL)
    {
        Node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                Node *next_next = temp->next->next;
                Node *nodetodelete = temp->next;
                delete (nodetodelete);
                temp->next = next_next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}
int main()
{
    Node *node1 = new Node(23);
    Node *head = node1;
    Inserthead(head, 6);
    Inserthead(head, 7);
    Inserthead(head, 2);
    Inserthead(head, 6);
    print(head);
    unsorted(head);
    print(head);

    return 0;
}