#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];

int main()
{
    int n, e;
    cin >> n >> e;

    
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    int q;
    cin >> q;

    
    while (q--)
    {
        int T_node;
        cin >> T_node;
        if (adj[T_node].empty())
        {
            cout << "-1" << endl; 
        }
        else
        {
            sort(adj[T_node].rbegin(), adj[T_node].rend());
            for (int connected_node : adj[T_node])
            {
                cout << connected_node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
