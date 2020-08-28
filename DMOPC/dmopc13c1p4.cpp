#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int dist[51][51];
bool graph[51][51];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int rows,columns; cin >> columns >> rows;
        int startx,starty,endx,endy;
        memset(dist,-1,sizeof dist);
        memset(graph,false,sizeof graph);
        char a;
        for (int x=1;x<=rows;++x){
            for (int y=1;y<=columns;++y){
                cin >> a;
                if (a=='X'){
                    continue;
                }
                graph[x][y]=true;
                if (a=='C'){
                    startx=x; starty=y;
                }
                else if (a=='W'){
                    endx=x; endy=y;
                }
            }
        }
        queue<pii> q; q.push({startx,starty});int x,y,count=0;
        while (!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;++i){
                x=q.front().first,y=q.front().second; q.pop();
                if (!graph[x][y]||dist[x][y]!=-1) continue;
                dist[x][y]=count;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
            count++;
            if (count>60){
                break;
            }
        }
        if (dist[endx][endy]<60&&dist[endx][endy]!=-1) cout << dist[endx][endy] << '\n';
        else cout << "#notworth" << '\n';
    }
}