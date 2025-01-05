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
    if (!head)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int search_item(Node *head, long long int target)
{
    int index = 0;
    while (head)
    {
        if (head->data == target)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}


void delete_na_korle_time_out(Node* head){
    while (head)
    {
        Node* tui_sesh = head;
        head = head->next;
        delete tui_sesh;
    }
    
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        long long int value;
        while (true)
        {
            cin >> value;
            if (value == -1)
            {
                break;
            }
            insert_at_tail(head, tail, value);
        }

        long long int target;
        cin >> target;
        cout << search_item(head, target) << endl;
        delete_na_korle_time_out(head);
    }

    return 0;
}
