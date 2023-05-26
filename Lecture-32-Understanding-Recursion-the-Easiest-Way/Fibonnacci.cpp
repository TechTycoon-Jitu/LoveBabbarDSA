#include <iostream>
using namespace std;

int fibonnacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans = fibonnacci(n - 1) + fibonnacci(n - 2);
  
    return ans;
}
int main()
{
    cout << "Enter a Number->" << endl;
    int n;
    cin >> n;
    int ans = fibonnacci(n);
    cout << ans << " ";

    return 0;
}