#include <iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << " source " << src << " destination " << dest << endl;
    // Base Case
    if (src == dest)
    {
        cout << "Reach Home";
        return;
    }
    // processing
    src++;
    // Recursive call
    reachHome(src, dest);
}
int main()
{
    int dest = 10;
    int src = 1;
    reachHome(src, dest);

    return 0;
}