#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> str, int count, int size)
{
    if (count == size / 2)
    {
        cout << "Middle of the element is->" << str.top() << endl;
        str.pop();
        return;
    }
    int num = str.top();
    str.pop();
    solve(str, count + 1, size);
    str.push(num);
}

void deletemiddle(stack<int> str, int size)
{
    int count = 0;
    solve(str, count, size);
}

int main()
{
    stack<int> str;
    str.push(3);
    str.push(5);
    str.push(9);        
    str.push(2);
    str.push(4);
    int size = str.size();
    deletemiddle(str, size);

    return 0;
}