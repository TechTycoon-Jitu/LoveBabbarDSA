#include <iostream>
using namespace std;
int getsum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    cout << "Enter the size of the array->" << endl;
    int n;
    cin >> n;

    // Create a variable size of array
    int *arr = new int[n];
    // taking input in array
    cout << "Enter your array->" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = getsum(arr, n);

    cout << "Answer is->" << ans << endl;
//case1:
    while(true)
    {
        int i = 5;
    }
//case2:
    while(true)
    {
        int *ptr = new int;
    }

    return 0;
}