#include <iostream>
using namespace std;
void likeawave(int arr[][3], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (i & 1)  //i%2 = =0
        {
            // ODD index->Bottom to top
            for (int j = row - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {

            for (int j = 0; j < row; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        
    }
}
int main()
{
    int arr[3][3];
    cout << "Enter your 2D array->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }
    cout << "The array's are->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col]<<" ";
        }
        cout << endl;
    }
    likeawave(arr, 3, 3);

    return 0;
}