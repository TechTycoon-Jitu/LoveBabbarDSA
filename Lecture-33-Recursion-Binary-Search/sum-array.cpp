#include <iostream>
using namespace std;
int getsum(int arr[], int size)
{
    // Base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int remainingpart = getsum(arr + 1, size - 1);
    int sum = arr[0] + remainingpart;
    return sum;
}
int main()
{
    int arr[5] = {3, 2, 5, 1, 6};
    int size = 5;

    int sum = getsum(arr, 5);

    cout << "sum is->" << sum;

    return 0;
}