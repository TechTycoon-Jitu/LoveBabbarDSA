#include<iostream>
#include<stack>
using namespace std;
void smallerelement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    int ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
   // return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the element->" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   smallerelement(arr,n);
   cout<<"smaller element->"<<endl;
   for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
   
   
    return 0;
}