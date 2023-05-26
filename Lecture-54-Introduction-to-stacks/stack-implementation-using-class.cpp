#include <iostream>
#include<stack>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack is overflow->" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is underflow->" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty->" << endl;
        }
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st(5);
    st.push(22);
    st.push(78);
    st.push(67);

    cout << "Top of the element is->" << st.peek() << endl;

    st.pop();
    cout << "Top of the element is->" << st.peek() << endl;

    st.pop();
    cout << "Top of the element is-> "<<st.peek() << endl;
    st.pop();

    

    if (st.isempty())
    {
        cout << "Stack is Empty->" << endl;
    }
    else
    {
        cout << "Stack is not Empty->" << endl;
    }

    return 0;
}