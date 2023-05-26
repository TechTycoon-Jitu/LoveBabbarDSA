/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    pair<int,int>diameterfirst(TreeNode*root)
    {
        if(root==NULL)
        {
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>left = diameterfirst(root->left);
        pair<int,int>right = diameterfirst(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second +1;

        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int val = diameterfirst(root).first;
        val = val-1;
        return val;
    }
};