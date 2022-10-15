#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

ll val[MAXN], down[MAXN], ret[MAXN];
struct Edge{ int n, w, nxt; } adj[2*MAXN];
int h[MAXN], T;

ll dfs(int v, int p){
    ret[v]=val[v];
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].n, w=adj[i].w;
        if (to==p) continue;
        dfs(to,v);
        if (w>1) ret[v]+=ret[to];
        else down[v]=max(down[v],down[to]);
    }
    down[v]+=ret[v];
    for (int i=h[v];i;i=adj[i].nxt){
        int to=adj[i].n, w=adj[i].w;
        if (to==p) continue;
        down[v]=max(down[v],ret[v]-ret[to]+down[to]);
    }
    return down[v];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> val[i];
    for (int i=1;i<=n-1;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[++T]={b,c,h[a]}, h[a]=T;
        adj[++T]={a,c,h[b]}, h[b]=T;
    }
    cout << dfs(1,1) << '\n';
}