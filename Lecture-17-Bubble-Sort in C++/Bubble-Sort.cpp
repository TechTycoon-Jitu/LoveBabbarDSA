#include <iostream>
using namespace std;
void Display(int arr[], int n)
{
    cout << "Arrays->" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Bubblesort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter your size of your array->" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array->" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting->" << endl;
    Display(arr, n);
    cout << "After sorting->" << endl;
    Bubblesort(arr, n);
    Display(arr, n);

    return 0;
}