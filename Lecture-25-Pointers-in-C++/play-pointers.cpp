#include <iostream>
using namespace std;
int main()
{
    // pointer to int is created,and pointing to some garbage address
    // int *p = 0;
    // cout<<*p<<endl;

    /*
     int i = 5;
     int *q = &i;
     cout << q << endl;
     cout << *q << endl;

     int *p = 0;
     p = &i;
     cout << p << endl;
     cout << *p << endl;
     */

    int num = 5;
    int a = num;
    cout << "a Before " << num << endl;
    a++;
    cout << "a Before " << num << endl;

    int *p = &num;
    cout << "Before " << num << endl;
    (*p)++;
    cout << "After " << num << endl;

    // coping a pointer
    int *q = p;
    cout << q << "-" << p << endl;
    cout << *p << "-" << *q << endl;

    // Important notes
    int i = 3;
    int *t = &i;
    // cout << (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;
    cout << "Before t " << t << endl;
    t = t + 1;
    cout << "After t" << t << endl;

    return 0;
}