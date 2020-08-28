#include <iostream>
#include <queue>

using namespace std;

char graph[100][100];
int dist[100][100];
int visited[100][100];

void camera(int x,int y){
    int i=1;
    while (true){
        if (graph[x+i][y]=='W'){
            break;
        }
        else if (graph[x+i][y]=='.' || graph[x+1][y]=='S'){
            graph[x+i][y]='V';
        }
        i++;
    }
    i=1;
    while (true){
        if (graph[x-i][y]=='W'){
            break;
        }
        else if (graph[x-i][y]=='.' || graph[x-1][y]=='S'){
            graph[x-i][y]='V';
        }
        i++;
    }
    i=1;
    while (true){
        if (graph[x][y+i]=='W'){
            break;
        }
        else if (graph[x][y+i]=='.' || graph[x][y+1]=='S'){
            graph[x][y+i]='V';
        }
        i++;
    }
    i=1;
    while (true){
        if (graph[x][y-i]=='W'){
            break;
        }
        else if (graph[x][y-i]=='.' || graph[x][y-1]=='S'){
            graph[x][y-i]='V';
        }
        i++;
    }
}

int main(){
    int rows,columns,sx,sy;
    cin >> rows >> columns;
    char temp;
    for (int i=0;i<rows;++i){
        for (int k=0;k<columns;++k){
            cin >> temp;
            graph[i][k]=temp;
        }
    }
    for (int i=0;i<rows;++i){
        for (int k=0;k<columns;++k){
            if (graph[i][k]=='S'){
                sx=i;
                sy=k;
            }
            else if (graph[i][k]=='C'){
                camera(i,k);
            }
        }
    }
    if (graph[sx][sy]=='V'){
        visited[sx][sy]=1;
        graph[sx][sy]='E';
    }
    int x,y,count=0;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    while (!q.empty()){
        int qsize=q.size();
        for (int _=0;_<qsize;++_){
            x=q.front().first;y=q.front().second;
            q.pop();
            while (true){
                if (visited[x][y]==1){
                    break;
                }
                else if (graph[x][y]=='U'){
                    visited[x][y]=1;
                    x--;
                }
                else if (graph[x][y]=='D'){
                    visited[x][y]=1;
                    x++;
                }
                else if (graph[x][y]=='L'){
                    visited[x][y]=1;
                    y--;
                }
                else if (graph[x][y]=='R'){
                    visited[x][y]=1;
                    y++;
                }
                else{
                    break;
                }
            }
            if (!visited[x][y] && graph[x][y]!='V' && graph[x][y]!='C' && graph[x][y]!='W'){
                if (dist[x][y]!=0){
                    dist[x][y]=min(dist[x][y],count);
                }
                else{
                    dist[x][y]=count;
                }
                if (graph[x][y]=='.' || graph[x][y]=='S'){
                    q.push(make_pair(x+1,y));
                    q.push(make_pair(x-1,y));
                    q.push(make_pair(x,y+1));
                    q.push(make_pair(x,y-1));
                }
            }
            visited[x][y]=1;
        }
        count++;
    }
    for (int i=0;i<rows;++i){
        for (int k=0;k<columns;++k){
            if (graph[i][k]=='.' || graph[i][k]=='V' ){
                if (dist[i][k]==0){
                    cout << -1 << '\n';
                }
                else{
                    cout << dist[i][k] << '\n';
                }
            }
        }
    }
}