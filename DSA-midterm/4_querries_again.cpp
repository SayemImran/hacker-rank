#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_head(Node *&head, Node *&tail, int val, int &counter)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    counter++;
}

void insert_tail(Node *&head, Node *&tail, int val, int &counter)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    counter++;
}

bool insert_at_idx(Node *&head, Node *&tail, int val, int idx, int &counter)
{
    if (idx < 0 || idx > counter)
    {
        cout << "Invalid" << endl;
        return false;
    }

    if (idx == 0)
    {
        insert_head(head, tail, val, counter);
    }
    else if (idx == counter)
    {
        insert_tail(head, tail, val, counter);
    }
    else
    {
        Node *tmp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            tmp = tmp->next;
        }
        Node *newnode = new Node(val);
        newnode->next = tmp->next;
        tmp->next->prev = newnode;
        tmp->next = newnode;
        newnode->prev = tmp;
        counter++;
    }
    return true;
}

void print_linked_list(Node *head)
{
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_linked_list_rev(Node *tail)
{
    cout << "R -> ";
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int qry, counter = 0;
    cin >> qry;
    while (qry--)
    {
        int pos, data;
        cin >> pos >> data;
        if (insert_at_idx(head, tail, data, pos, counter))
        {
            print_linked_list(head);
            print_linked_list_rev(tail);
        }
    }
    return 0;
}
