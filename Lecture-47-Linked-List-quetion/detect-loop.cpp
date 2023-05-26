#include <iostream>
#include <map>
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
void Insertathead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        temp = head;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void Insertattail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp = tail;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
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
bool detectloop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "visited on element->" << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
bool floyddetectloop(Node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "Cycle is present at->" << slow->data << endl;
            return true;
        }
    }
    return false;
}
int main()
{
    Node *node1 = new Node(78);
    Node *head = node1;
    Node *tail = node1;
    Insertattail(tail, 10);
    Insertattail(tail, 21);
    Insertattail(tail, 32);
    Insertattail(tail, 2);
    print(head);
    tail->next = head->next->next;
    if (detectloop(head))
    {
        cout << "Loop is present" << endl;
    }
    else
    {
        cout << "Loop is not present" << endl;
    }
    if (floyddetectloop(head))
    {
        cout << "Loop is present." << endl;
    }
    else
    {
        cout << "Loop is not present." << endl;
    }

    return 0;
}