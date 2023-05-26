#include <iostream>
using namespace std;
bool search2Dmatrix(int arr[][4], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = arr[mid / col][mid % col];
        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    int arr[3][4];
    cout << "Enter your 2D array in sorted order->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "Your 2D array is->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    int target;
    cout << "Enter your target->" << endl;
    cin >> target;
     
    cout << "The element is found(1) or not(0)->" << search2Dmatrix(arr, 3, 4, target) << endl;

    return 0;
}