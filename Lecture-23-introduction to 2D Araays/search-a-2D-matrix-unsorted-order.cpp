#include <iostream>
using namespace std;
bool searcha2Dmatrixunsortedorder(int arr[][4], int row, int col, int target)
{
    int rowindex = 0;
    int colindex = col - 1;
    while (rowindex < row && colindex >= 0)
    {
        int element = arr[rowindex][colindex];
        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            rowindex++;
        }
        else
        {
            colindex--;
        }
    }
    return 0;
}
int main()
{
    int arr[3][4];
    cout << "Enter your array in unsorted order->" << endl;
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
    cout << "Enter your target->" << endl;
    int target;
    cin >> target;
    cout << "If the element is found then print 1 otherwise 0-> " << searcha2Dmatrixunsortedorder(arr, 3, 4, target);

    return 0;
}