#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int rows,columns;

bool in(int x,int y){
    if (x<0 || x>=rows || y<0 || y>=columns){
        return false;
    }
    return true;
}

int main(){

    char a;
    cin >> rows >> columns;
    char cat[rows][columns];
    int visited[rows][columns]={0},traps=0;
    for (int k=0;k<rows;++k){
        for (int i=0;i<columns;++i){
            cin >> a;
            cat[k][i]=a;
            visited[k][i]=0;
        }
    }
    for (int x=0;x<rows;++x){
        for (int y=0;y<columns;++y){
            if (!visited[x][y]){
                traps+=1;
                queue<pair<int,int>> q;
                q.push(make_pair(x,y));
                while (!q.empty()){
                    int x1=q.front().first,y1=q.front().second;
                    q.pop();
                    if (!visited[x1][y1]){
                        if (cat[x1][y1]=='N' && in(x1-1,y1)){
                            q.push(make_pair(x1-1,y1));
                        }
                        if (cat[x1][y1]=='E' && in(x1,y1+1)){
                            q.push(make_pair(x1,y1+1));
                        }
                        if (cat[x1][y1]=='S' && in(x1+1,y1)){
                            q.push(make_pair(x1+1,y1));
                        }
                        if (cat[x1][y1]=='W' && in(x1,y1-1)){
                            q.push(make_pair(x1,y1-1));
                        }
                        if (cat[x1+1][y1]=='N' && in(x1+1,y1)){
                            q.push(make_pair(x1+1,y1));
                        }
                        if (cat[x1-1][y1]=='S' && in(x1-1,y1)){
                            q.push(make_pair(x1-1,y1));
                        }
                        if (cat[x1][y1-1]=='E' && in(x1,y1-1)){
                            q.push(make_pair(x1,y1-1));
                        }
                        if (cat[x1][y1+1]=='W' && in(x1,y1+1)){
                            q.push(make_pair(x1,y1+1));
                        }
                    }
                    visited[x1][y1]=1;
                }
            }
        }
    }
    cout << traps << '\n';
}