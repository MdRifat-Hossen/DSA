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
// bool search(Node *root, int data)
// {
//     if (root == NULL)
//     {

//         return false;
//     }
//     if (root->data == data)
//     {
//         return true;
//     }
//     if (root->data > data)
//     {
//         // left part;
//         return search(root->left, data);
//     }
//     else
//     {
//         return search(root->right, data);
//     }
// }
Node *minVal(Node *root)
{
    Node *tmp = root;
    while (tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}
Node *maxVal(Node *root)
{
    Node *tmp = root;
    while (tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    return tmp;
}
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
void InOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
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
Node *deleteNode(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0chile
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // -------
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }
        // right chiled
        if (root->left == NULL && root->right != NULL)
        {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }
        // 2 childs
        if (root->left != NULL && root->right != NULL)
        {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
}
int main()
{
    // 10 8 21 7 27 5 4 3 -1
    Node *root = NULL;
    cout << "Enter the Data for BST: " << endl;
    takeInput(root);

    cout << "IN-Order Traversal: " << endl;
    InOrderTraversal(root);

    // int data;
    // cout << endl
    //      << "Enter the Search Data: " << endl;
    // cin >> data;
    // if (search(root, data) == true)
    // {
    //     cout << "Yes " << data << " is present" << endl;
    // }
    // else
    // {
    //     cout << "No" << endl;
    // }
    cout << endl
         << "Min Value is :" << minVal(root)->data << endl;
    cout << "Max Value is :" << maxVal(root)->data << endl;
    root = deleteNode(root, 50);

    cout << "IN-Order Traversal: " << endl;
    InOrderTraversal(root);
    cout << endl
         << "Min Value is :" << minVal(root)->data << endl;
    cout << "Max Value is :" << maxVal(root)->data << endl;
    return 0;
}