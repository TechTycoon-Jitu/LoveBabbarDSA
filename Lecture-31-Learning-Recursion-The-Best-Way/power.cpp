#include <iostream>
using namespace std;
int power(int n)
{
    // Base case
    if (n == 0)
        return 1;
    // recursive relation
    int smallerproblem = power(n - 1);
    int biggerproblem = 2 * smallerproblem;

    return biggerproblem;
}
int main()
{
    cout << "Enter the size->";
    int n;
    cin >> n;
    int ans = power(n);
    cout << "Answer is->" << ans;

    return 0;
}