#include <iostream>
#include <stack>
using namespace std;
void insertsort(stack<int> &s,int num)
{
    if(s.empty() || (!s.empty() && s.top()<num))
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    insertsort(s,num);
    s.push(n);

}
 void sort(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sort(s);
    insertsort(s, num);
}
int main()
{
    stack<int> s, st;
    s.push(1);
    s.push(9);
    s.push(5);
    s.push(6);
    st = s;
    cout << "Before sort->";
    int num = st.top();
    cout << num;
    for (int i = 0; i <= st.size(); i++)
    {
        st.pop();
        int num = st.top();
        cout << num;
    }
    cout<<endl;
    sort(s);
    cout<<"after sort->";
    while(!s.empty())
    {
        cout<<s.top()<<"";
        s.pop();
    }

    return 0;
}