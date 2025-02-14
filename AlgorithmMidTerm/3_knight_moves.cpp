#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char grid[N][N];
bool vis[N][N];
int level[N][N];
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    
    while (!q.empty()) {
        pair<int, int> parent = q.front();
        int par_i = parent.first;
        int par_j = parent.second;
        q.pop();

        for (auto child : d) {
            int ci = par_i + child.first;
            int cj = par_j + child.second;

            if (valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        int src_i, src_j, dst_i, dst_j;
        cin >> src_i >> src_j >> dst_i >> dst_j;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(src_i, src_j);
        cout << level[dst_i][dst_j] << endl;
    }

    return 0;
}
