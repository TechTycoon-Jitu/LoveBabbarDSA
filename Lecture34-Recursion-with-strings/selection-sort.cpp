#include <iostream>
using namespace std;
void selectionsort(int arr[], int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }
    int minindex = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < arr[minindex])
        {
            minindex = i;
        }
    }
    swap(arr[minindex], arr[start]);
    selectionsort(arr, start + 1, end);
}
int main()
{
    int arr[5] = {3, 2, 7, 5, 1};
    selectionsort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}