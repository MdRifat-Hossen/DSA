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
int solve(BinaryTreeNode<int> *root, int &i, int n)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int left = solve(root->left, i, n);
    if (left != -1)
    {
        return left;
    }
    // N
    i++;
    if (i == n)
    {
        return root->data;
    }
    int right = solve(root->right, i, n);
    return right;
}
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    // Write your code here.
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}