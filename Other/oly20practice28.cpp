#include <bits/stdc++.h>

using namespace std;
bool graph[105][105];
bool visited[105][105];

int dfs(int x,int y){
    if (visited[x][y]||!graph[x][y]) return 0;
    visited[x][y]=true;
    int size=1;
    size+=dfs(x+1,y);
    size+=dfs(x-1,y);
    size+=dfs(x,y+1);
    size+=dfs(x,y-1);
    return size;
}

int main(){
    int rows, columns, k; cin >> rows >> columns >> k;
    for (int i=0,a,b;i<k;++i){
        cin >> a >> b;
        graph[a][b]=true;
    }
    int maximum=0;
    for (int x=1;x<=rows;++x){
        for (int y=1;y<=columns;++y){
            if (!visited[x][y]&&graph[x][y]) maximum=max(maximum,dfs(x,y));
        }
    }
    cout << maximum << '\n';
}