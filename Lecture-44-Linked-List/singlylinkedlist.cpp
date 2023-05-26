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
    ~Node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data" << value << endl;
    }
};
void InsertatTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void Insertathead(Node *&head, int data)
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
void InsertatPosition(Node *&tail, Node *&head, int position, int d)
{
    if (position == 1)
    {
        Insertathead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertatTail(tail, d);
        return;
    }
    Node *Inserttomiddle = new Node(d);
    Inserttomiddle->next = temp->next;
    temp->next = Inserttomiddle;
}
void deleteNode(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void deletenode(Node *&head, int value)
{
    if (value == head->data)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        while (value != curr->data)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(45);
    Node *head = node1;
    Node *tail = node1;

    cout << "Insertathead->" << endl;
    Insertathead(head, 89);
    Insertathead(head, 83);
    Insertathead(head, 45);
    Insertathead(head, 32);
    Insertathead(head, 98);
    Insertathead(head, 99);
    print(head);

    /*
    cout << "InsertatTail->" << endl;
    InsertatTail(tail, 23);
    InsertatTail(tail, 45);
    InsertatTail(tail, 32);
    InsertatTail(tail, 67);
    print(head);
    */
    // InsertatPosition(tail, head, 6, 1);
    // print(head);
    deletenode(head, 99);
    print(head);

    return 0;
}