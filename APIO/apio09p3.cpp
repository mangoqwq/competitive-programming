#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

struct Edge{ int n, nxt; } graph[MAXN], adj[MAXN], adjr[MAXN];
int h1[MAXN], h2[MAXN], h3[MAXN], i1, i2, i3;
bitset<MAXN> vis;
int out[MAXN], T, scc[MAXN], arr[MAXN], val[MAXN], dist[MAXN];

void dfs1(int curr){
    vis[curr]=1;
    for (int i=h1[curr];i!=0;i=adj[i].nxt){
        int x=adj[i].n;
        if (vis[x]) continue;
        dfs1(x);
    }
    out[++T]=curr;
}

void dfs2(int curr){
    scc[curr]=T; val[T]+=arr[curr];
    for (int i=h2[curr];i!=0;i=adjr[i].nxt){
        int x=adjr[i].n;
        if (scc[x]==T) continue;
        if (scc[x]!=0) graph[++i3]={T,h3[scc[x]]}, h3[scc[x]]=i3;
        else dfs2(x);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        adj[++i1]={b,h1[a]}, h1[a]=i1;
        adjr[++i2]={a,h2[b]}, h2[b]=i2;
    }
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i) if (!vis[i]) dfs1(i);
    T=0;
    for (int i=n;i>=1;--i) if (!scc[out[i]]) T++, dfs2(out[i]);
    int src, q; cin >> src >> q;
    ms(dist,-0x3f); dist[scc[src]]=val[scc[src]];
    for (int j=1;j<=T;++j){
        for (int i=h3[j];i!=0;i=graph[i].nxt){
            int x=graph[i].n;
            dist[x]=max(dist[x],dist[j]+val[x]);
        }
    }
    int ans=0;
    for (int i=1,a;i<=q;++i){
        cin >> a;
        ans=max(ans,dist[scc[a]]);
    }
    cout << ans << '\n';
    
}