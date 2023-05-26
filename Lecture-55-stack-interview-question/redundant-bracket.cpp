// Obsiously Given string is a valis expession
#include <iostream>
#include <stack>
using namespace std;
bool redundant(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '*' || ch == '/' || ch == '-')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isredundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '*' || top == '/' || top == '-')
                    {
                        isredundant = false;
                    }
                    s.pop();
                }
                if (isredundant == true)
                {
                    return true;
                }
                s.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "((a*b+(c/d)))";
    if (redundant(str))
    {
        cout << "Redundant bracket is there." << endl;
    }
    else
    {
        cout << "Redundant bracket is not there." << endl;
    }

    return 0;
}