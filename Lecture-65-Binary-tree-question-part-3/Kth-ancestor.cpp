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
BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root,int targetNodeVal,int &k)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==targetNodeVal)
    {
        return root;
    }
   BinaryTreeNode<int> *leftans =  solve(root->left,targetNodeVal,k);
    BinaryTreeNode<int> * rightans = solve(root->right,targetNodeVal,k);
    if(leftans!=NULL && rightans==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL && rightans!=NULL)
    {
         k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;

}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    BinaryTreeNode<int> * ans = solve(root,targetNodeVal,k);
    if(ans==NULL || ans->data==targetNodeVal)
    {
        return -1;
    }
    return ans->data;
}
