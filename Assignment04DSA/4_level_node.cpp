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

void node_at_level(Node *root, int Tlevel)
{
    if (root == NULL)
    {
        return;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    bool found = false;

    while (!q.empty())
    {
        Node *tmp = q.front().first;
        int level = q.front().second;
        q.pop();

        if (level == Tlevel)
        {
            cout << tmp->data << " ";
            found = true;
        }

        if (tmp->left != NULL)
            q.push({tmp->left, level + 1});
        if (tmp->right != NULL)
            q.push({tmp->right, level + 1});
    }

    if (!found)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    vector<int> vec;
    int lvl;
    Node *root = node_input();
    cin >> lvl;
    node_at_level(root, lvl);
    return 0;
}