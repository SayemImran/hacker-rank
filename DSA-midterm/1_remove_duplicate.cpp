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
        return;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}


void removeDuplicate(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }
    Node* tmp = head;
    list<int> lst;
    while(tmp != NULL){
        lst.push_back(tmp->data);
        tmp = tmp->next;
    }
    lst.sort();
    lst.unique();

    for(int it : lst){
        cout<<it<<" ";
    }
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
    removeDuplicate(head,tail);
    return 0;
}