#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool isVisited[1001][1001];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int row, col;

bool valid(int si, int sj)
{
    return si >= 0 && si < row && sj >= 0 && sj < col && graph[si][sj] == '.' && !isVisited[si][sj];
}

int dfs(int si, int sj)
{
    isVisited[si][sj] = true;
    int roomSize = 1;

    for (int i = 0; i < 4; i++)
    {
        int child_i = si + direction[i].first;
        int child_y = sj + direction[i].second;

        if (valid(child_i, child_y))
        {
            roomSize += dfs(child_i, child_y);
        }
    }

    return roomSize;
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> graph[i][j];
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
                int size = dfs(i, j);
                roomSizes.push_back(size);
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
        cout<<roomSizes.front()<<endl;

    }

    return 0;
}