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
Node *solve(Node *&first, Node *&second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;
    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1== NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node *mergelist(Node *&first, Node *&second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
int main()
{
    Node *node1 = new Node(5);
    Node *first = node1;
    insertathead(first, 3);
    insertathead(first, 1);
    cout << "First sorted linked list->" << endl;
    print(first);
    Node *node2 = new Node(5);
    Node *second = node2;
    insertathead(second, 4);
    insertathead(second, 2);
    cout << "Second sorted linked list->" << endl;
    print(second);
    Node *merge = mergelist(first, second);
    print(merge);
    return 0;
}