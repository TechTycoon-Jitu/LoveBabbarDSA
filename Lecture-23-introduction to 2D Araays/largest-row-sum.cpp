#include <iostream>
using namespace std;
int largerowsum(int arr[][4], int row, int col)
{
    int maxi = INT_MIN;
    int rowindex = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "sum = " << sum << " ";
        if (sum > maxi)
        {
            maxi = sum;
            rowindex = i;
        }
    }
    cout <<endl<< "The maximum sum is ->" << maxi << endl;
    return rowindex;
}
int main()
{
    int arr[3][4];
    cout << "Enter the array->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "The 2D arrays are->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    int index = largerowsum(arr, 3, 4);
    cout << "Max row at index is :" << index << endl;

    return 0;
}