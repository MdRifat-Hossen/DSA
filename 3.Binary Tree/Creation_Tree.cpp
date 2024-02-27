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
    while (!q.empty())
    {
        node *tmp = q.front();

        cout << tmp->data << " ";
        q.pop();
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

int main()
{
    node *root = NULL;
    root = boultTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Lever Order traversal
    cout << "Lever Order Traversal : " << endl;
    LeverOrderTraversal(root);
    return 0;
}