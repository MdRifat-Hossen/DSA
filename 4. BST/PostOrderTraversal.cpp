#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertBTS(Node *root, int data)
{
    // base case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (root->data < data)
    {
        // Right Part jao
        root->right = insertBTS(root->right, data);
    }
    else
    {
        root->left = insertBTS(root->left, data);
    }
    return root;
}
void PostOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBTS(root, data);
        cin >> data;
    }
}
int main()
{
    // 10 8 21 7 27 5 4 3 -1
    Node *root = NULL;
    cout << "Enter the Data for BST: " << endl;
    takeInput(root);

    cout << "Post-Order Traversal: " << endl;
    PostOrderTraversal(root);

    return 0;
}