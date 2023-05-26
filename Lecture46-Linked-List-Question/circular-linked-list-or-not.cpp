#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        while (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data->" << value << endl;
    }
};
void InsertNode(Node *&tail, int element, int d)
{
    // For empty list
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        // present at least 1 node
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // create a node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
bool iscircular(Node *&tail)
{
    if (tail == NULL)
    {
        return true;
    }
    Node *temp = tail->next;
    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    if (temp == tail)
    {
        return true;
    }
}

int main()
{
    Node *tail = NULL;
    InsertNode(tail, 5, 3);
    print(tail);
    InsertNode(tail, 3, 5);
    print(tail);
    InsertNode(tail, 5, 8);
    print(tail);
    InsertNode(tail, 8, 10);
    print(tail);
    InsertNode(tail, 5, 7);
    print(tail);
    if (iscircular(tail))
    {
        cout << "Linked list is circular->" << endl;
    }
    else
    {
        cout << "Linked list is not circular->" << endl;
    }
    return 0;
}