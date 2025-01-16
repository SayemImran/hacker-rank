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
    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int lval, rval;
        cin >> lval >> rval;

        if (lval != -1)
        {
            parent->left = new Node(lval);
            q.push(parent->left);
        }
        if (rval != -1)
        {
            parent->right = new Node(rval);
            q.push(parent->right);
        }
    }
    return root;
}

void printLeft(Node *root, vector<int> &lv)
{
    if (root == NULL)
        return;

    lv.push_back(root->data);
    if (root->left)
        printLeft(root->left, lv);
    else if (root->right)
        printLeft(root->right, lv);
}

void printRight(Node *root, vector<int> &rv)
{
    if (root == NULL)
        return;

    rv.push_back(root->data);
    if (root->right)
        printRight(root->right, rv);
    else if (root->left)
        printRight(root->left, rv);
}

int main()
{
    Node *root = node_input();
    if (root == NULL)
        return 0;

    vector<int> left, right;
    printLeft(root, left);
    printRight(root, right);

    // jokhon left child nai
    if (!root->left)
    {
        for (int dt : right)
        {
            cout << dt << " ";
        }
        cout << endl;
    }
    // jokhon right child nai
    else if (!root->right)
    {
        reverse(left.begin(), left.end());
        for (int dt : left)
        {
            cout << dt << " ";
        }
        cout << endl;
    }
    // jokhon left right 2 tai ache
    else
    {
        vector<int> rmvfirst = right;
        reverse(rmvfirst.begin(), rmvfirst.end());
        rmvfirst.pop_back();
        reverse(rmvfirst.begin(), rmvfirst.end());

        reverse(left.begin(), left.end());
        left.insert(left.end(), rmvfirst.begin(), rmvfirst.end());

        for (int dt : left)
        {
            cout << dt << " ";
        }
        cout << endl;
    }

    return 0;
}
