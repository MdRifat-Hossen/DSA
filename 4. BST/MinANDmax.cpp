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
    cout << "Min Value is :" << minVal(root)->data << endl;
    cout << "Max Value is :" << maxVal(root)->data << endl;
    return 0;
}