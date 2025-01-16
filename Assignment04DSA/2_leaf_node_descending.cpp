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

void leaf_node_descending(Node *root, vector<int> &ln_data)
{
    
    if (root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        ln_data.push_back(root->data);
        return;
    }
    leaf_node_descending(root->left,ln_data);
    leaf_node_descending(root->right,ln_data);

}

int main()
{
    vector<int> vec;
    Node *root = node_input();
    leaf_node_descending(root,vec);
    sort(vec.rbegin(), vec.rend());
    for(int dt : vec){
        cout<<dt<<" ";
    }
    return 0;
}