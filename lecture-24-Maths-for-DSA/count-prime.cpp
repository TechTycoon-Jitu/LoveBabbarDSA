#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int prime(int n)
{
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isprime(i))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    cout << "Enter a Number->" << endl;
    int n;
    cin >> n;
    cout << "count is ->" << prime(n) << endl;

    return 0;
}
