#include <bits/stdc++.h>
using namespace std;

void printOperation(const list<long long int> &l)
{
    cout << "L -> ";
    for (int item : l)
    {
        cout << item << " ";
    }
    cout << endl;
}

void printOperationBack(const list<long long int> &l)
{
    cout << "R -> ";
    for (auto it = l.rbegin(); it != l.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<long long int> linked_list;
    int q;
    int counter = 0;
    cin >> q;
    while (q--)
    {
        int x;
        long long int v;
        cin >> x >> v;
        if (x == 0)
        {
            linked_list.push_front(v);
            counter++;
        }
        else if (x == 1)
        {
            linked_list.push_back(v);
            counter++;
        }
        else if (x == 2)
        {
            if (v == 0)
            {
                if (!linked_list.empty())
                {
                    linked_list.pop_front();
                    counter--;
                }
            }
            else if (v > 0 && v < counter)
            {
                linked_list.erase(next(linked_list.begin(),v));
                counter--;
            }
        }
        printOperation(linked_list);
        printOperationBack(linked_list);
    }
    return 0;
}
