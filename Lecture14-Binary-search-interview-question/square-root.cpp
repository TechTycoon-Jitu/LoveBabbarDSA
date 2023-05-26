#include <iostream>
using namespace std;
long long int squareroot(int n)
{
    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
double moreprecision(int n, int precision, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int key;
    cout << "Enter a key that you want to find the root->" << endl;
    cin >> key;
    cout << "Sqaure root of the key is ->" << squareroot(key)<<endl;
    int tempsol = squareroot(key);
    cout << "Sqaure root of the key after point->" << moreprecision(key, 3, tempsol);

    return 0;
}