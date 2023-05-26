#include <iostream>
using namespace std;
void spiralprint(int arr[][4], int row, int col)
{
    int count = 0;
    int total = row * col;
    // index initialization
    int startingrow = 0;
    int startingcol = 0;
    int endingrow = row - 1;
    int endingcol = col - 1;
    while (count < total)
    {
        // print starting row
        for (int index = startingcol; count < total && index <= endingcol; index++)
        {
            cout << arr[startingrow][index]<<" ";
            count++;
        }

        startingrow++;
        // print ending col
        for (int index = startingrow; count < total && index <= endingrow; index++)
        {
            cout << arr[index][endingcol]<<" ";
            count++;
        }
        endingcol--;
        // print ending row
        for (int index = endingcol; count < total && index >= startingcol; index--)
        {
            cout << arr[endingrow][index]<<" ";
            count++;
        }

        endingrow--;
        // print starting col
        for (int index = endingrow; count < total && index >= startingrow; index--)
        {
            cout << arr[index][startingcol]<<" ";
            count++;
        }
        startingcol++;
    }
}
int main()
{
    int arr[3][4];
    cout << "Enter your 2D array->" << endl;
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
    spiralprint(arr, 3, 4);

    return 0;
}