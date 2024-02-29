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
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        if (tmp == NULL)
        {
            cout << endl;
            if (!q.empty())
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
    cout << "Printing the The BST: " << endl;
    LevelOrderTraversal(root);
    return 0;
}