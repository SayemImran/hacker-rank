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

void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

bool CheckPalindrome(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;

    while (i != NULL && j != NULL)
    {
        if (i->data != j->data)
        {
            return false;
        }
        i = i->next;
        j = j->prev;
    }
    return true;
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
    bool chk = CheckPalindrome(head,tail);
    if(chk){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}