#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q; 
    int t;
    cin >> t; 

    while (t--)
    {
        int n;
        cin >> n; 

        if (n == 0)
        {
            string name;
            cin >> name; 
            q.push(name); 
        }
        else if (n == 1)
        {
            if (!q.empty())
            {
                cout << q.front() << endl; 
                q.pop(); 
            }
            else
            {
                cout << "Invalid" << endl; 
            }
        }
    }

    return 0;
}
