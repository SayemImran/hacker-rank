#include<bits/stdc++.h>
using namespace std;

char adj_list[1005][1005];
bool isVisited[1005][1005];
vector<pair<int,int>> discover_node = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool isValid(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    return true;
}

void dfs(int si, int sj){
    isVisited[si][sj] = true;
    for(int i=0; i<4; i++){
        int ci = si+discover_node[i].first;
        int cj = sj+discover_node[i].second;

        if(isValid(ci,cj) && !isVisited[ci][cj] && adj_list[ci][cj]=='.'){
            dfs(ci,cj);
        }
    }
}


int main()
{
    cin>>n>>m;
    memset(isVisited, false, sizeof(isVisited));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>adj_list[i][j];
        }
    }
    int src_i, src_j;
    cin>>src_i>>src_j;

    dfs(src_i,src_j);

    int dst_i, dst_j;
    cin>>dst_i>>dst_j;

    if(isVisited[dst_i][dst_j]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}