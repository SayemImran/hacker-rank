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

void insert_at_head(Node *&head, Node *&tail, long long int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, long long int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void delete_at_head(Node *&head)
{
    if (head == NULL)
    {
        return;
    } 
    Node *dlt = head;
    head = head->next;
    delete dlt;
}

void delete_at_any_idx(Node *&head, Node *&tail, int idx)
{
    if (head == NULL || idx < 0)
        return; 
    
    if (idx == 0)
    { 
        delete_at_head(head);// ডিলেট করলাম হেড
        // এখন হেড ডিলেট করার পর টেইল আপডেট করলাম
        if (head == NULL)
        {
            tail = NULL;
        } 
        return;
    }
    Node *tmp = head;
    for (int i = 1; i < idx && tmp->next != NULL; i++)
    {
        tmp = tmp->next;
    }
    if (tmp->next == NULL)
    {
        return;
    } 
    Node *dlt = tmp->next;
    tmp->next = tmp->next->next;
    if (tmp->next == NULL)
    {
        tail = tmp;
    } 
    delete dlt;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        long long int v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);
        }
        else if (x == 1)
        {
            insert_at_tail(head, tail, v);
        }
        else if (x == 2)
        {
            delete_at_any_idx(head, tail, v);
        }
        print_linked_list(head);
    }
    return 0;
}
