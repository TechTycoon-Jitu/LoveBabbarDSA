#include <iostream>
using namespace std;
long long nthstairs(long long n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    long long ans = nthstairs(n - 1) + nthstairs(n - 2);

    return ans;
}
int main()
{
    cout << "Enter the stairs number->" << endl;
    long long n;
    cin >> n;
    long long ans = nthstairs(n);
    cout << ans;
    return 0;
}