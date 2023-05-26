#include <iostream>
using namespace std;
int Binarysearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int getpivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
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
int findposition(int arr[], int n, int k)
{
    int pivot = getpivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    { // Binary search second line
        return Binarysearch(arr, pivot, n - 1, k);
    }
    else
    { // Binary search first line
        return Binarysearch(arr, 0, pivot - 1, k);
    }
}
int main()
{
    int arr[5] = {12, 15, 18, 2, 4};
    int key;
    cout << "Enter a numeber that you want to find it->" << endl;
    cin >> key;
    cout << "key is present at index->" << findposition(arr, 5, key);

    return 0;
}