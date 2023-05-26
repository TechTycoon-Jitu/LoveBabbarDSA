#include <iostream>
using namespace std;
bool ispresent(int arr[][4], int target, int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    // create 2D array
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,12};
    // int arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    int arr[3][4];

    // taking input->row wise input
    cout << "Enter the 2D array->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }

    /* // taking input->col wise input
     cout << "Enter the 2D array->" << endl;
     for (int col = 0; col < 4; col++)
     {
         for (int row = 0; row < 3; row++)
         {
             cin >> arr[row][col];
         }
     }*/

    // output
    cout << "The 2D arrays are->" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Enter the element to search->" << endl;
    int target;
    cin >> target;
    if (ispresent(arr, target, 3, 4))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}