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

void createmapping(vector<int> &inorder, map<int,int>&nodetoindex, int n){
    for(int i = 0; i< n; i++){
       nodetoindex[inorder[i]]=i;
    }
}
TreeNode<int>* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n,map<int,int>&nodetoindex){
    if(index >= n || inorderStart > inorderEnd)
        return NULL;
    
    int element = preorder[index++];
    TreeNode<int> *root = new TreeNode<int>(element);
    int pos = nodetoindex[element];
    
    root->left = solve(inorder, preorder, index, inorderStart, pos-1, n,nodetoindex);
    root->right = solve(inorder, preorder, index, pos+1, inorderEnd, n,nodetoindex);
    
    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int preOrderIndex = 0;
    int n = preorder.size();
    map<int,int>nodetoindex;
    createmapping(inorder,nodetoindex,n);
    TreeNode<int>* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n,nodetoindex);
    return ans;
}