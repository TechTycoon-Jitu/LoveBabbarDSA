#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // Base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        // Back track
        swap(nums[index], nums[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the vector->" << endl;
    cin >> n;
    int a;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    int index = 0;
    vector<vector<int>> ans;
    solve(nums, ans, index);
     for (int j = 0; j < ans.size(); j++)
    {
        for (int k = 0; k < ans[j].size(); k++)
        {
            cout << ans[j][k] << " ";
        }    
        cout << endl;
    }

    return 0;
}