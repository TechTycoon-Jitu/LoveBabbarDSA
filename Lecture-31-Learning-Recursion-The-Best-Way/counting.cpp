#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    //recursive relation
    print(n - 1);
}

int main()
{
    cout << "Enter your Number that you want to print it->" << endl;
    int n;
    cin >> n;
    cout << "Counting->" << endl;
    print(n);

    return 0;
}