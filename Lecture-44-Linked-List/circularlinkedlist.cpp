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
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "The List is empty please check it again->" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // only 1 node
        if (curr == prev)
        {
            tail = NULL;
        }
        //>=2 node
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
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
    deleteNode(tail, 5);
    print(tail);
    return 0;
}