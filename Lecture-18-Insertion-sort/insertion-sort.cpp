#include <iostream>
using namespace std;
void Display(int arr[], int n)
{
    cout << "Arrays->" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int n;
    cout << "Enter your size of the array->" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting->" << endl;
    Display(arr, n);
    cout << "After sorting->" << endl;
    insertionsort(arr, n);
    Display(arr, n);

    return 0;
}