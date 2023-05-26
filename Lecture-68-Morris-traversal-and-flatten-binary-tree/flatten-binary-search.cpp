#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *current = root;
    while(current!=NULL)
    {
      if (current->left) {
        TreeNode<int> *prev = current->left;
        while (prev->right != NULL)
          prev = prev->right;
          prev->right = current->right;
        current->right = current->left;
        current->left = NULL;
      }
      current = current->right;
    }
    
    return root;
}