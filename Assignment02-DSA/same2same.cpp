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
    tail->next = newnode;
    tail = newnode;
}

bool same_naki_vai(Node *head1, Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if(head1 == NULL && head2 ==NULL){
        return true;
    }
    return false;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int data;
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        insert_at_tail(head1, tail1, data);
    }
    while (true)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, data);
    }

    if (!same_naki_vai(head1, head2))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}