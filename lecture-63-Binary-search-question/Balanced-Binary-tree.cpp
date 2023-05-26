#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
pair<bool,int>balancefast(BinaryTreeNode<int>* root) {


     if(root==NULL)
    {
        pair<bool,int>p = make_pair(true,0);
        return p;
    }
    pair<bool,int>left = balancefast(root->left);
    pair<bool,int>right = balancefast(root->right);

    bool leftfast = left.first;
    bool rightfast = right.first;
    bool diff = abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.second = max(left.second,right.second)+1;
    if(leftfast&&rightfast&&diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first= false;
    }
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return balancefast(root).first;
}