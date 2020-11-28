#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=501;

struct uwu{ int x, y; bool c; };
int n, m, xs, ys, xe, ye;
vector<uwu> adj[MAXN][2*MAXN];
int dist[MAXN][2*MAXN][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n >> ys >> xs >> ye >> xe; 
    char a;
    for (int i=0;i<2*n+1;++i){
        if (i%2==0){
            for (int j=0;j<m;++j){
                cin >> a;
                if (a=='n') continue;
                adj[i/2][j].push_back({i/2,j+1,a=='b'});
                adj[i/2][j+1].push_back({i/2,j,a=='b'});
            }
        }
        else{
            for (int j=0;j<2*m+1;++j){
                cin >> a;
                if (a=='n') continue;
                if (j%2==0) adj[i/2][j/2].push_back({i/2+1,j/2,a=='b'}), adj[i/2+1][j/2].push_back({i/2,j/2,a=='b'});
                else adj[i/2][j/2+1].push_back({i/2+1,j/2,a=='b'}), adj[i/2+1][j/2].push_back({i/2,j/2+1,a=='b'});
            }
        }
    }
    ms(dist,0x3f);
    queue<uwu> q; q.push({xs,ys,0}), q.push({xs,ys,1}); dist[xs][ys][0]=dist[xs][ys][1]=0;
    while (!q.empty()){
        int x=q.front().x, y=q.front().y; bool c=q.front().c; 
        q.pop();
        for (uwu to:adj[x][y]){
            if (to.c==c||dist[to.x][to.y][to.c]<=dist[x][y][c]+1) continue;
            
            dist[to.x][to.y][to.c]=dist[x][y][c]+1;
            q.push(to);
        }
    }
    cout << min(dist[xe][ye][0],dist[xe][ye][1]) << '\n';
}