#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
}
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve( myStack,x);
    return myStack;
}int main()
{
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);
    pushAtBottom(s, 9);
   // cout << "top of the element is->" << s.top() << endl;
   for (int i = 0; i < s.size(); i++)
   {
       int num = s.top();
       if(num==9)
       {
        cout<<"successful."<<endl;
       }
       else{
        s.pop();
       }
   }
   

    return 0;
}