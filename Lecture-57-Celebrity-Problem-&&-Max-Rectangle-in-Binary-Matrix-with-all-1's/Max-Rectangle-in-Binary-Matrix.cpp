#include <iostream>
#include <stack>
#include<vector>
using namespace std;
int nextsmallerelement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for (int i = n - 1; i >= 0; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        int ans = s.top();
        s.push(i);
    }
    return ans;
}
int prevsmallerelement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int>ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        int ans = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(int *heights, int n)
{
   vector<int>ans(n);
    next = nextsmallerelement(heights, n);
    vector<int>prev(n);
    prev = prevsmallerelement(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}
int maxArea(int M[MAX][MAX], int n, int m)
{
    int area = largestRectangleArea(M[0], m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
            {
                M[i][j] = 0;
            }
            else
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
        }
        int newarea = largestRectangleArea(M[i], m);
        area = max(area, newarea);
    }
    return area;
}
int main() {
    int T;
    cin >> T;
    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
    return 0;
}