#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int find_difference(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int minn = head->data;
    int maxi = head->data;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data < minn)
        {
            minn = temp->data;
        }
        if (temp->data > maxi)
        {
            maxi = temp->data;
        }
        temp = temp->next;
    }

    return maxi - minn;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        insert_at_tail(head, tail, data);
    }

    int difference = find_difference(head);
    cout << difference << endl;

    return 0;
}
