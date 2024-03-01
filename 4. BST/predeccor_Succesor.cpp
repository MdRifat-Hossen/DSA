/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode *tmp = root;
    int pred = -1;
    int succ = -1;
    // find key
    while (tmp->data != key)
    {
        if (tmp->data > key)
        {
            succ = tmp->data;
            tmp = tmp->left;
        }
        else
        {
            pred = tmp->data;
            tmp = tmp->right;
        }
    }
    // pred succ
    TreeNode *leftTree = tmp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // succ

    TreeNode *rightTree = tmp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}