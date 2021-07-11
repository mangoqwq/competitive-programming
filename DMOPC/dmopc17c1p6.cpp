#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1, SZ=1000;

int n, q; 
struct Query{ char op; int x, y, z=0; };
vector<Query> qs[MAXN];

int blk[MAXN];
unordered_map<int,int> adj[MAXN], tmp[MAXN];
unordered_map<int,pair<int,int>> g[MAXN];
int rt[MAXN], dist[MAXN];

namespace Rebuild{
    void dfs(int v, int p, int d, int src){
        rt[v]=src, dist[v]=d;
        for (auto [to,w]:tmp[v]){
            if (to==p) continue;
            dfs(to,v,d^w,src);
        }
    }
    void go(vector<Query> &qs){
        for (int i=1;i<=n;++i){
            rt[i]=0, dist[i]=0;
            g[i].clear();
            tmp[i]=adj[i];
            g[i].clear();
        }
        for (auto [op,x,y,z]:qs){
            if (op=='R'&&adj[x].count(y)){
                tmp[x].erase(y);
                tmp[y].erase(x);
            }
        }
        for (int i=1;i<=n;++i) if (!rt[i]) dfs(i,i,0,i);
        for (auto [op,x,y,z]:qs){
            if (op=='R'&&adj[x].count(y)){
                g[rt[x]][y]={adj[x][y],x};
                g[rt[y]][x]={adj[y][x],y};
            }
        }
    }
}

namespace LCT{
    int ans;
    void link(int x, int y, int z){
        adj[x][y]=z;
        adj[y][x]=z;
        g[rt[x]][y]={adj[x][y],x};
        g[rt[y]][x]={adj[y][x],y};
    }
    void cut(int x, int y){
        adj[x].erase(y);
        adj[y].erase(x);
        g[rt[x]].erase(y);
        g[rt[y]].erase(x);
    }
    void tree(int v, int p, int d, int t){
        if (rt[v]==rt[t]) ans=d^dist[v]^dist[t];
        for (auto [to,pii]:g[rt[v]]){
            auto [w,u]=pii;
            if (to==p) continue;
            tree(to,u,d^dist[v]^dist[u]^w,t);
        }
    }
    void go(vector<Query> &qs){
        for (auto [op,x,y,z]:qs){
            if (op=='Q') ans=-1;
            if (op=='A') link(x,y,z);
            if (op=='R') cut(x,y);
            if (op=='Q') tree(x,x,0,y);
            if (op=='Q') cout << ans << '\n';
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=q;++i) blk[i]=i/SZ;
    vector<Query> graph;
    for (int i=1;i<=n-1;++i){
        int x, y, z; cin >> x >> y >> z;
        graph.push_back({'A',x,y,z});
    } 
    LCT::go(graph);
    for (int i=1;i<=q;++i){
        char op; cin >> op;
        int x, y, z=0;
        if (op=='A') cin >> x >> y >> z;
        else cin >> x >> y;
        qs[blk[i]].push_back({op,x,y,z});
    }
    for (int i=0;i*SZ<=q;++i){
        Rebuild::go(qs[i]);
        LCT::go(qs[i]);
    }
}