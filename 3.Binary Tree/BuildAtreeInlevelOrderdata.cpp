#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *boultTree(node *root)
{
    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter Data for Left side Inserting: " << data << endl;
    root->left = boultTree(root->left);
    cout << "Enter the Data for Right side Inserting: " << data << endl;
    root->right = boultTree(root->right);
    return root;
}

void LeverOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *tmp = q.front();

        q.pop();
        if (tmp == NULL) // Old Level complete
        {
            cout << endl;
            if (!q.empty()) // queue still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << tmp->data << " ";
            if (tmp->left)
            {
                q.push(tmp->left);
            }
            if (tmp->right)
            {
                q.push(tmp->right);
            }
        }
    }
}
void InOder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    InOder(root->left);        // L
    cout << root->data << " "; // N
    InOder(root->right);       // R
}
void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postOrder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
node *builtTreeLeverOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter the for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *tmp = q.front();
        q.pop();
        cout << "Enter the Data for left node: " << tmp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            tmp->left = new node(leftData);
            q.push(tmp->left);
        }
        cout << "Enter the Data for right node: " << tmp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            tmp->right = new node(rightData);
            q.push(tmp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    builtTreeLeverOrder(root);
    // root = boultTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // // Lever Order traversal
    // cout << "Lever Order Traversal : " << endl;
    // LeverOrderTraversal(root);

    // cout << "InOder Traversal: ";
    // InOder(root);
    // cout << endl;
    // cout << "PreOrder Traversal: ";
    // preorder(root);
    // cout << endl;
    // cout << "Post Order Traversal: ";
    // postOrder(root);
    return 0;
}