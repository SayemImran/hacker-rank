#include <bits/stdc++.h>
using namespace std;

int leader[100005];
int leader_size[100005];

int find(int node)
{
    if (leader[node] == -1)
        return node;
    return leader[node] = find(leader[node]); 
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (leader1 != leader2)
    {
        if (leader_size[leader1] >= leader_size[leader2])
        {
            leader[leader2] = leader1;
            leader_size[leader1] += leader_size[leader2];
        }
        else
        {
            leader[leader1] = leader2;
            leader_size[leader2] += leader_size[leader1];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    memset(leader, -1, sizeof(leader));
    for (int i = 1; i <= n; i++)
        leader_size[i] = 1;

    int cycle = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            cycle++; 
        }
        else
        {
            dsu_union(a, b);
        }
    }

    cout << cycle << endl;
    return 0;
}
