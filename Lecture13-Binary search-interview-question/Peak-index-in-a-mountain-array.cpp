#include <iostream>
using namespace std;
int peakmountain(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
int main()
{
    int arr[10] = {3, 4, 5, 6, 7, 8, 9, 10, 2, 1};
    cout << "Peak index in a mountain array->" << peakmountain(arr, 10) << endl;
    return 0;
}