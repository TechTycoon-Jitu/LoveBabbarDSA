#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
    }
    else{
    int num = s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(num);
    }
    
}
void reverse(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,num);
    return;
}
int main()
{
    stack<int>s,st;
    s.push(3);
    s.push(4);
    s.push(7);
    st = s;
    cout<<"before reverse->";
    int num = st.top();
    cout<< num ;
    for (int i = 0; i <= st.size(); i++)
    {
        st.pop();
        int num = st.top();
        cout<< num;
    }
    cout<<endl;
    
    reverse(s);
    cout<<"after reverse->";
    while(!s.empty())
    {
        cout<<s.top()<<"";
        s.pop();
    }
    
    

    return 0;
}