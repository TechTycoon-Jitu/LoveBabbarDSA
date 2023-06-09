#include <iostream>
#include <stack>
using namespace std;
bool parenthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (!s.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    string str = "[({}]";

    if (parenthesis(str))
    {
        cout << "This is a valid parenthesis->" << endl;
    }
    else
    {
        cout << "This is not a valid parenthesis->" << endl;
    }
    return 0;
}