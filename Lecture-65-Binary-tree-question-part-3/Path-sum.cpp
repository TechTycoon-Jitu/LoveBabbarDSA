#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
 void solve(TreeNode < int > * root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;

        path.push_back(root->data);

        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);

        //check for K Sum

        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }

        path.pop_back();
    }
int noWays(TreeNode < int > * root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
}