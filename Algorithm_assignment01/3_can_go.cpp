#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

char graph[MAX][MAX];
bool isVisited[MAX][MAX];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int row, col;
pair<int, int> start, dest;

bool valid(int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < col);
}

void dfs(int sr, int sc)
{
    isVisited[sr][sc] = true;

    for (int i = 0; i < 4; i++)
    {
        int child_row = sr + direction[i].first;
        int child_col = sc + direction[i].second;

        if (valid(child_row, child_col) && !isVisited[child_row][child_col] &&
            (graph[child_row][child_col] == '.' || graph[child_row][child_col] == 'B'))
        {
            dfs(child_row, child_col);
        }
    }
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'A')
                start = {i, j};

            if (graph[i][j] == 'B')
                dest = {i, j};
        }
    }

    memset(isVisited, false, sizeof(isVisited));

    dfs(start.first, start.second);

    if (isVisited[dest.first][dest.second])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
