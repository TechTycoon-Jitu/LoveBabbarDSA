#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* createParentmapping(BinaryTreeNode<int>*root,int target,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&nodeTomapping)
{
    BinaryTreeNode<int>*res = NULL;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    nodeTomapping[root] = NULL;
    while(!q.empty())
    {
        BinaryTreeNode<int>*front = q.front();
        q.pop();
        if(front->data==target)
        {
            res = front;
        }
        if(front->left)
        {
            nodeTomapping[front->left] = front;
            q.push(front->left);
        }
        if(front->right)
        {
            nodeTomapping[front->right] = front;
            q.push(front->right);
        }
    }
    return res;

}
int burntree(BinaryTreeNode<int>*root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&nodeTomapping)
{
    
    map<BinaryTreeNode<int>*,bool>visited;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while(!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for(int i = 0;i<size;i++)
        {
            BinaryTreeNode<int>*front = q.front();
            q.pop();
            if(front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if(front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] =true;
            }
            if(nodeTomapping[front]&&!visited[nodeTomapping[front]])
            {
                flag = true;
                q.push(nodeTomapping[front]);
                visited[nodeTomapping[front]]=true;
            }
        }
        if(flag == 1)
        {
            ans++;
        }
    }
    return ans;

}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>nodeTomapping;
    BinaryTreeNode<int>*TargetNode = createParentmapping(root,start,nodeTomapping);
   int ans =  burntree(TargetNode,nodeTomapping);
     return ans;

}
