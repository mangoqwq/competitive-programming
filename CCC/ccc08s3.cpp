#include <iostream>
#include <queue>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int _=0;_<cases;++_){
        int x,y;
        cin >> y >> x;
        char maze[x][y],temp;
        int dist[x][y];
        for (int __=0;__<y;++__){
            for (int ___=0;___<x;++___){
                cin >> temp;
                maze[___][__]=temp;
                dist[___][__]=100000;
            }
        }
        dist[0][0]=1;
        int a,b;
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        if (maze[x-1][y-1]=='*'){
            cout << -1 << '\n';
        }
        else {
        while (!q.empty()){
            a=q.front().first;
            b=q.front().second;
            if (a==x-1 && b==y-1){
                break;
            }
            q.pop();
            if ((maze[a][b]=='+') || (maze[a][b]=='|')){
                if (b-1>-1){
                    if (dist[a][b]+1<dist[a][b-1]){
                        q.push(make_pair(a,b-1));
                        dist[a][b-1]=dist[a][b]+1;
                    }
                }
                if (b+1<y){
                    if (dist[a][b]+1<dist[a][b+1]){
                        q.push(make_pair(a,b+1));
                        dist[a][b+1]=dist[a][b]+1;
                    }
                }

            }
            if ((maze[a][b]=='+') || (maze[a][b]=='-')){
                if (a-1>-1){
                    if (dist[a][b]+1<dist[a-1][b]){
                        q.push(make_pair(a-1,b));
                        dist[a-1][b]=dist[a][b]+1;
                    }
                }
                if (a+1<x){
                    if (dist[a][b]+1<dist[a+1][b]){
                        q.push(make_pair(a+1,b));
                        dist[a+1][b]=dist[a][b]+1;
                    }
                }
            }

            
        }
        if (dist[x-1][y-1]==100000){
            cout << -1 << '\n';
        }
        else{
            cout << dist[x-1][y-1] << '\n';
        }
        }

    }
}