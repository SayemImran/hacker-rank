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

void remove_duplicates(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *prev = current;
        Node *temp = current->next;

        while (temp != NULL)
        {
            if (temp->data == current->data)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    remove_duplicates(head);

    print_linked_list(head);

    return 0;
}
