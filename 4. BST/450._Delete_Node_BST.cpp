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
    TreeNode *max(TreeNode *root)
    {
        TreeNode *tmp = root;
        while (tmp->right != NULL)
        {
            tmp = tmp->right;
        }
        return tmp;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // base case;
        if (root == NULL)
        {
            return root;
        }
        if (root->val == key)
        {
            // 0childs
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 1 childs
            // left part
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            // right part
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            }
            // 2 child
            if (root->left != NULL && root->right != NULL)
            {
                int min = max(root->left)->val;
                root->val = min;
                root->left = deleteNode(root->left, min);
                return root;
            }
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};