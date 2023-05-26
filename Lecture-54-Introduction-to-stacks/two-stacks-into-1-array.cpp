#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
        else
        {
            cout << "Stack is full->" << endl;
        }
    }
    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
        else
        {
            cout << "Stack is full" << endl;
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    Stack st(5);
    st.push1(3);
    st.push1(7);
    st.push1(8);
    st.push2(2);
    st.push2(1);

    cout<<"pop ->"<<st.pop2()<<endl;

    return 0;
}