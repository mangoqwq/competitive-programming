#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
bool graph[1005][1005];
int dist[1005][1005];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    memset(dist,-1,sizeof dist);
    int r,c; cin >> r >> c;
    int sx,sy,ex,ey; cin >> sx >> sy >> ex >> ey;
    sx++;sy++;ex++;ey++;
    char a;
    for (int x=1;x<=r;++x){
        for (int y=1;y<=c;++y){
            cin >> a;
            if (a=='O'){
                graph[x][y]=true;
            }
        }
    }
    queue<pii> q; q.push({sx,sy}); int count=0; int x,y;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=0;i<qsize;++i){
            x=q.front().first; y=q.front().second; q.pop();
            if (dist[x][y]!=-1||!graph[x][y]) continue;
            dist[x][y]=count;
            q.push({x+1,y});
            q.push({x-1,y});
            q.push({x,y+1});
            q.push({x,y-1});
        }
        count++;
    }
    int t; cin >> t;
    int ans=0;
    while (t--){
        cin >> x >> y;
        x++;y++;
        if (dist[x][y]!=-1)
        ans=max(ans,dist[ex][ey]-dist[x][y]);
    }
    cout << ans << '\n';
}