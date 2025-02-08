#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool isVisited[1001][1001];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int row, col;

bool valid(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col && graph[x][y] == '.'; 
}

int dfs(int sr, int sc)
{
    isVisited[sr][sc] = true;
    int roomSize = 1;

    for (int i = 0; i < 4; i++)
    {
        int child_row = sr + direction[i].first;
        int child_col = sc + direction[i].second;

        if (valid(child_row, child_col) && !isVisited[child_row][child_col])
        {
            roomSize += dfs(child_row, child_col); 
        }
    }
    return roomSize;
}

int main()
{
    cin >> row >> col;

    if (row <= 0 || col <= 0) {
        return 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != '.' && graph[i][j] != '#' ) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    memset(isVisited, false, sizeof(isVisited));

    vector<int> roomSizes;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (graph[i][j] == '.' && !isVisited[i][j])
            {
                int roomSize = dfs(i, j);
                roomSizes.push_back(roomSize);
            }
        }
    }

    if (roomSizes.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        sort(roomSizes.begin(), roomSizes.end());

        for (int size : roomSizes)
        {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
