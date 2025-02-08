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
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        bool found = false;

        if (s == d)
        {
            found = true;
        }
        else
        {
            for (int child : adj[s])
            {
                if (child == d)
                {
                    found = true;
                    break;
                }
            }
        }

        if (found)
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
