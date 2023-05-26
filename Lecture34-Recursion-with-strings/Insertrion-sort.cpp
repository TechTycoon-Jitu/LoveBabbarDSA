#include <iostream>
using namespace std;
void insertionsort(int arr[], int start, int end)
{
    while (start > end)
    {
        return;
    }
    int current = arr[start];
    int j = start - 1;
    while (arr[j] > current && j >= 0)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = current;
    insertionsort(arr, start + 1, end);
}
int main()
{
    int arr[5] = {3, 2, 7, 5, 1};
    insertionsort(arr, 1, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}