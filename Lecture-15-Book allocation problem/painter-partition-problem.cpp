#include <iostream>
using namespace std;
bool ispossible(int arr[], int n, int m, int mid)
{
    int painterscount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + arr[i] <= mid)
        {
            pagesum = pagesum + arr[i];
        }
        else
        {
            painterscount++;
            if (painterscount > m || arr[i] > mid)
            {
                return false;
            }
            pagesum = arr[i];
        }
    }
    return true;
}
int painterpartion(int arr[], int n, int m)
{
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (ispossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr[4] = {5, 5, 5, 5};
    int painter;
    cout << "Enter the number of painter->" << endl;
    cin >> painter;
    cout << "Painter partition ->" << painterpartion(arr, 4, painter);

    return 0;
}