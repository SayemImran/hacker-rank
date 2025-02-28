#include <bits/stdc++.h>
using namespace std;


long long int dist[1005];  

class Edge {
public:
    int a, b;
    long long int c;
    Edge(int a, int b, long long int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;

bool bellman_ford(int s, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = LLONG_MAX;  
    }
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto ed : edge_list) {
            int a = ed.a;
            int b = ed.b;
            long long int c = ed.c;
            if (dist[a] != LLONG_MAX && dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
            }
        }
    }

    // Check for negative cycles
    for (auto ed : edge_list) {
        int a = ed.a;
        int b = ed.b;
        long long int c = ed.c;
        if (dist[a] != LLONG_MAX && dist[a] + c < dist[b]) {
            cout << "Negative Cycle Detected" << endl;
            return false;
        }
    }

    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    // Read edges into the edge_list
    while (e--) {
        int a, b;
        long long int c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    // Run Bellman-Ford
    if (!bellman_ford(src, n)) {
        return 0;  //negative ashle ar agabo na. ekhanei khatam bye bye tata good bye
    }

    int t;
    cin >> t;
    while (t--) {
        int dst;
        cin >> dst;

        if (dist[dst] == LLONG_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[dst] << endl;
        }
    }

    return 0;
}
