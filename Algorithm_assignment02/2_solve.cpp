#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX // INF হিসেবে 10^18 বা LLONG_MAX ব্যবহার করবো

 // সর্বোচ্চ 100 নোড হতে পারে
long long dist[105][105]; // 1-based index নেয়ার জন্য N+1

int main()
{
    int n, e;
    cin >> n >> e;

    // 1. **ডিস্ট্যান্স ম্যাট্রিক্স ইনিশিয়ালাইজ করা**
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;  // নিজের কাছে যেতে খরচ 0
            else dist[i][j] = INF;       // শুরুতে সবাই INF
        }
    }

    // 2. **এজ ইনপুট নেওয়া (মাল্টিপল এজ থাকলে মিনিমাম নেওয়া)**
    for (int i = 0; i < e; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w); // যদি মাল্টিপল এজ থাকে, ছোটোটি রাখবো
    }

    // 3. **Floyd-Warshall Algorithm**
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 4. **Query Process করা**
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        if (dist[x][y] == INF)
            cout << -1 << "\n";  // যদি কোনো রাস্তা না থাকে
        else
            cout << dist[x][y] << "\n"; // মিনিমাম কস্ট প্রিন্ট করবো
    }

    return 0;
}
