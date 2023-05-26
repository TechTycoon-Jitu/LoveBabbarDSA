#include <iostream>
using namespace std;
int& func(int n)
{
    int num = a;
    int& ans = num;
    return ans;
}
void update2(int &n)
{
    n++;
}
void update1(int n)
{
    n++;
}
int main()
{
    /* int i = 5;
     // create a reference variable
     int &j = i;
     cout << i << endl;
     i++;
     cout << i << endl;
     j++;
     cout << i << endl;
     cout << j << endl;
     */
    int n = 5;
    cout << "Before update->" << n << endl;
    update2(n);
    cout << "After update->" << n << endl;

    return 0;
}