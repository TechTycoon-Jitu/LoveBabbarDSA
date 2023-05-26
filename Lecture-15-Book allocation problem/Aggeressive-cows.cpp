#include <iostream>
using namespace std;
bool ispossible(int arr[], int n, int m, int mid)
{
    int cowcount = 1;
    int lastposition = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastposition >= mid)
        {
            cowcount++;
            if (cowcount == m)
            {
                return true;
            } 
            lastposition = arr[i];
        }
    }
    return false;
}
int aggressivecows(int arr[], int n, int m)
{
    // sort(arr.begin(),arr.end());
    int s = 0;

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (ispossible(arr, n, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 10};
    int cows;
    cout << "Enter the amount of cows->" << endl;
    cin >> cows;
    cout << "Aggressive cows->" << aggressivecows(arr, 5, cows);

    return 0;
}