#include <iostream>
using namespace std;
void rotatematrix(int arr[][4], int row, int col)
{
    cout << "90degree 2D array->" << endl;

    for (int newrow = 0; newrow < 4; newrow++)
    {
        for (int newcol = 1; newcol < 5; newcol++)
        {

            cout << arr[row - newcol][newrow] << " ";
        }

        cout << endl;
    }
}
int main()
{
    int arr[4][4];
    cout << "Enter 2D array->" << endl;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "Your 2D arrays are->" << endl;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    rotatematrix(arr, 4, 4);

    return 0;
}