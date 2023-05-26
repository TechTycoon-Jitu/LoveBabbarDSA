#include <iostream>
#include <queue>
using namespace std;
int main()
{
    deque<int>d;
    d.push_front(12);
    d.push_back(14);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.pop_back();

    if(d.empty())
    {
        cout<<"Dequeue is Empty->"<<endl;
    }
    else
    {
        cout<<"Dequeue is not Empty->"<<endl;
    }

   /* queue<int> q;

    q.push(11);
    cout << "The front of the quesue is->" << q.front() << endl;

    q.push(12);
    cout << "The front of the quesue is->" << q.front() << endl;

    q.push(23);
    cout << "The front of the quesue is->" << q.front() << endl;

    cout << "Size of the queue is->" << q.size() << endl;
    q.pop();
    cout << "Size of the queue is->" << q.size() << endl;

    if (q.empty())
    {
        cout << "The queue is Empty." << endl;
    }
    else
    {
        cout << "The queue is not Empty." << endl;
    }
    */

    return 0;
}