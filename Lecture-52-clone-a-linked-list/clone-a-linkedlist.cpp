#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *arbit;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arbit = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "->" << temp->data << "(" << temp->arbit->data << ")"
             << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *colonelist(Node *head)
{
    map<Node *, Node *> mp;
    Node *temp, *nhead;
    temp = head;
    nhead = new Node(temp->data);
    mp[temp] = nhead;
    while (temp->next != NULL)
    {
        nhead->next = new Node(temp->next->data);
        temp = temp->next;
        nhead = nhead->next;
        mp[temp] = nhead;
    }
    temp = head;
    while (temp != NULL)
    {
        mp[temp]->arbit = mp[temp->arbit];
        temp = temp->next;
    }
    return mp[head];
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->arbit = head->next->next;
    head->next->arbit = head;
    head->next->next->arbit = head->next->next->next->next;
    head->next->next->next->arbit = head->next->next;
    head->next->next->next->next->arbit = head->next;
    cout << "The orginal linked list->" << endl;
    print(head);
    Node *sol = colonelist(head);
    cout << "The cloned linked list:\n";
    print(sol);

    return 0;
}