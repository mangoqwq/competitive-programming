#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

struct Coord{ int x, y; };
queue<Coord> q;
struct Edge{
    int v, w;
    bool operator<(const Edge &x) const{
        return w>x.w;
    }
};
priority_queue<Edge> pq;
vector<Edge> adj[MAXN];
int dist[MAXN];

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int g[n+1][m+1], id[n+1][m+1], ans[n+1][m+1], T=0;
    ms(g,0), ms(id,0), ms(ans,0);
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        char a; cin >> a;
        g[i][j]=a=='#';
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!g[i][j]||id[i][j]) continue;
            id[i][j]=++T;
            q.push({i,j});
            while (!q.empty()){
                auto [x,y]=q.front(); q.pop();
                for (int dx=-1;dx<=1;++dx){
                    for (int dy=-1;dy<=1;++dy){
                        if (abs(dx+dy)!=1) continue;
                        if (x+dx<1||x+dx>n||y+dy<1||y+dy>m) continue;
                        if (g[x+dx][y+dy]&&!id[x+dx][y+dy]){
                            id[x+dx][y+dy]=T;
                            q.push({x+dx,y+dy});
                        }
                    }
                }
            }
        }
    }
    for (int j=1;j<=m;++j){
        int pre=0, lastc=n+1;
        for (int i=n;i>=1;--i){
            if (!id[i][j]) continue;
            if (id[i][j]!=pre){
                adj[pre].push_back({id[i][j],lastc-i-1});
                pre=id[i][j];
            }
            lastc=i;
        }
    }
    ms(dist,0x3f);
    dist[0]=0;
    pq.push({0,0});
    while (!pq.empty()){
        auto [v,d]=pq.top(); pq.pop();
        for (auto [to,w]:adj[v]){
            if (dist[to]>d+w){
                dist[to]=d+w;
                pq.push({to,dist[to]});
            }
        }
    }
    for (int i=1;i<=n;++i) for (int j=1;j<=m;++j){
        if (id[i][j]) ans[i+dist[id[i][j]]][j]=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cout << (ans[i][j]?'#':'.');
        }
        cout << '\n';
    }
}