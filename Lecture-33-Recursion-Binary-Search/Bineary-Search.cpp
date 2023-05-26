#include <iostream>
using namespace std;
void print(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool binearysearch(int arr[], int start, int end, int key)
{
    print(arr, start, end);
    // Base case

    // Element not found
    if (start > end)
    {
        return false;
    }
    int mid = start + (end - start) / 2;
    cout << "Mid is ->" << arr[mid] << endl;
    // elemnt found
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid > key])
    {
        return binearysearch(arr, mid + 1, end, key);
    }
    else
    {
        return binearysearch(arr, start, mid - 1, key);
    }
}
int main()
{
    int arr[5] = {2, 5, 7, 8, 9};
    int size = 5;
    int key = 9;
    bool present = binearysearch(arr, 0, 5, key);
    if (present)
    {
        cout << "Key is present->" << endl;
    }
    else
    {
        cout << "Key is not present->" << endl;
    }

    return 0;
}