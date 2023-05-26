#include <iostream>
using namespace std;
void print(int *p)
{
    cout << p << endl;
    cout << *p << endl;
}
void update(int *p)
{
   // p = p+1;
    //cout<<"Inside->"<<p<<endl;
    *p = *p+1;
}
int getsum(int arr[],int n)
{
    cout<<endl<<"size->"<<sizeof(arr)<<endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum+arr[i];
    }
    return sum;
    
}

int main()
{
    int value = 5;
    int *p = &value;
    cout<<value<<endl;
   // print(p);
   cout<<"Before->"<<*p<<endl;
   update(p);
   cout<<"After->"<<*p<<endl;

   int arr[6] = {1,2,3,4,5,8};
   cout<<"sum is "<<getsum(arr+3,3)<<endl;

    return 0;
}
