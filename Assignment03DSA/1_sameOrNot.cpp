#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> qu;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        st.push(data);
    }
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;
        qu.push(data);
    }
    bool matcher = true;
    if (n != m)
    {
        cout << "NO" << endl;
    }
    else
    {
        while (!st.empty() && !qu.empty())
        {
            if (st.top() != qu.front())
            {
                matcher = false;
                break;
            }
            st.pop();
            qu.pop();
        }
        if (matcher)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}