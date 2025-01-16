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

Node *node_input()
{
    int data;
    cin >> data;
    Node *root;
    if (data == -1)
    {
        cout << "Root can't invalid";
        return 0;
    }
    else
    {
        root = new Node(data);
    }

    queue<Node *> nodebox;
    nodebox.push(root);

    while (!nodebox.empty())
    {
        Node *parent = nodebox.front();
        nodebox.pop();

        int lval, rval;
        cin >> lval >> rval;

        Node *leftchild;
        Node *rightchild;

        if (lval == -1)
            leftchild = NULL;
        else
            leftchild = new Node(lval);
        if (rval == -1)
            rightchild = NULL;
        else
            rightchild = new Node(rval);

        parent->left = leftchild;
        parent->right = rightchild;

        if (parent->left)
            nodebox.push(parent->left);
        if (parent->right)
            nodebox.push(parent->right);
    }
    return root;
}

int sum_of_leaf_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int left_sum = sum_of_leaf_nodes(root->left);
    int right_sum = sum_of_leaf_nodes(root->right);

    return root->data + left_sum + right_sum;
}

int main()
{
    Node *root = node_input();
    int sum = sum_of_leaf_nodes(root);
    cout << sum << endl;
    return 0;
}