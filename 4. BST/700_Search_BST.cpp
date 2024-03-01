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
class Solution
{
public:
    TreeNode *search(TreeNode *root, int data)
    {
        if (root == NULL)
        {

            return NULL;
        }
        if (root->val == data)
        {
            return root;
        }
        if (root->val > data)
        {
            // left part;
            return search(root->left, data);
        }
        else
        {
            return search(root->right, data);
        }
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // base case
        return search(root, val);
    }
};