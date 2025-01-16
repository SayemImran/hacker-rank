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

bool yo_I_am_perfect(Node *root)
{
    if (root == NULL)
        return true;

    queue<pair<Node *, int>> q;
    q.push({root, 1});

    int leaf_depth_ini = -1;

    while (!q.empty())
    {
        Node *tmp = q.front().first;
        int level = q.front().second;
        q.pop();

        if (tmp->left == NULL && tmp->right == NULL)
        {

            if (leaf_depth_ini == -1)
            {
                leaf_depth_ini = level;
            }
            else if (leaf_depth_ini != level)
            {
                return false;
            }
        }

        else
        {
            if (tmp->left == NULL || tmp->right == NULL)
            {
                return false;
            }
            q.push({tmp->left, level + 1});
            q.push({tmp->right, level + 1});
        }
    }
    return true;
}

int main()
{
    vector<int> vec;
    Node *root = node_input();
    bool check = yo_I_am_perfect(root);

    if (check)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}