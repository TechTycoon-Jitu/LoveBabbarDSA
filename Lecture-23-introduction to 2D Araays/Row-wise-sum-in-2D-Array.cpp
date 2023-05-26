#include <iostream>
using namespace std;
// to print row wise sum
void printsum(int arr[][4], int row, int col)
{
    cout << "Printing sum->" << endl;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum = sum + arr[row][col];
        }
        cout << "sum = " << sum << " ";
    }
    cout << endl;
}
//to print col wise sum
void printcolsum(int arr[][4],int row,int col)
{
    for (int col = 0; col < 4; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum = sum+arr[row][col];
        }
        cout<<"sum = "<<sum<<" ";
    }
    cout<<endl;
    
}
int main()
{
    int arr[3][4];
    cout << "Enter the element of the array->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "The elements of 2D array's are ->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col]<<" ";
        }
        cout<<endl;
    }
    printsum(arr, 3, 4);
    printcolsum(arr,3,4);

    return 0;
}