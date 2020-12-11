#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2005;

struct Coord{ int x, y; } s, e;
vector<Coord> tele[26];
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=0;i<=n+1;++i) for (int j=0;j<=m+1;++j) grid[i][j]='#';
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        cin >> grid[i][j];
        if (grid[i][j]=='S') s={i,j};
        else if (grid[i][j]=='G') e={i,j};
        else if (grid[i][j]!='#' && grid[i][j]!='.'){
            tele[grid[i][j]-'a'].push_back({i,j});
        }
    }
    ms(dist,0x3f); dist[s.x][s.y]=0;
    queue<Coord> q; q.push(s);
    while (!q.empty()){
        Coord c=q.front(); q.pop();
        char curr=grid[c.x][c.y];
        if (curr>='a' && curr<='z'){
            for (Coord x:tele[curr-'a']){
                if (dist[x.x][x.y]>dist[c.x][c.y]+1)
                    dist[x.x][x.y]=dist[c.x][c.y]+1, q.push(x);
            }
            tele[curr-'a'].clear();
        }
        for (int i=-1;i<=1;++i)
            for (int j=-1;j<=1;++j){
                if (abs(i+j)!=1) continue;
                if (grid[c.x+i][c.y+j]=='#') continue;
                if (dist[c.x][c.y]+1<dist[c.x+i][c.y+j])
                    dist[c.x+i][c.y+j]=dist[c.x][c.y]+1, q.push({c.x+i,c.y+j});
            }
    }
    cout << (dist[e.x][e.y]==0x3f3f3f3f?-1:dist[e.x][e.y]) << '\n';
}