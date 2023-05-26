#include <iostream>
using namespace std;

int factorial(int n)
{
    // base case
    if (n == 0)
        return 1;
    // This is one way to print factorial
    /*
    int smallerproblem = factorial(n - 1);
    int biggerproblem = n * smallerproblem;

    return biggerproblem;*/
    // This is second way to print factorial
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;

    return 0;
}